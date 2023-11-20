import requests
import json
from datetime import datetime
from bs4 import BeautifulSoup

from urllib3.exceptions import InsecureRequestWarning
from urllib3 import disable_warnings

def generate_data(semester, department, completed_courses):
    
    disable_warnings(InsecureRequestWarning)
    
    # Assign urls for associated forms
    base_url = 'http://appl101.lsu.edu/booklet2.nsf/Selector2?OpenForm'
    post_url = 'http://appl101.lsu.edu/booklet2.nsf/f5e6e50d1d1d05c4862584410071cd2e?CreateDocument'

    soup = BeautifulSoup(requests.get(base_url).content, 'lxml')

    semesters = []
    for s in soup.select('[name="SemesterDesc"] [value]'):
        semesters.append(s['value'])

    departments = []
    for d in soup.select('[name="Department"] option'):
        departments.append(d.get_text(strip=True))

    # Dictionary 
    data = {
        '%%Surrogate_SemesterDesc': 1,
        'SemesterDesc': semester,
        '%%Surrogate_Department': 1,
        'Department': department
    }

    # Request the data with inputted semester and department
    r = requests.post(post_url, data=data, verify=False)
    getUrl = r.url

    if getUrl == "https://appl101.lsu.edu/booklet2.nsf/NoCourseDept?readform":
        print("No courses found") # Throw an error if no courses show up
    else:
        # Process course data
        soup = BeautifulSoup(requests.get(getUrl, verify=False).content, 'html.parser')

        # Find the course data within the HTML content, assuming it is the only within <pre> tags
        course_block = soup.find('pre').get_text(strip=True)
        course_entries = course_block.split('\n')[2:][:-5] # Skip the first 3 lines and last 5 lines

        # For testing purposes, write the course block to a file
        with open('course_block.txt', 'w') as text_file:
            text_file.write(course_block)

    # Initialize lists and variables
    course_data = []
    course_meta_data = []
    degree_audit_data = []
    last_index = None
    completed_course_list = list(completed_courses)
    course = {}
    course_meta = {}
    degree_audit = {}
        
    # Iterate through course data lines
    for i in range(1, len(course_entries)):
        line = course_entries[i]
        if line.lstrip().startswith('*') or "TBA" in line[60:64]: # Ignore lines starting with *
            continue
        else:
            available = line[0:3].strip()
            enrolled = line[6:9].strip()
            if (len(available) >= 1) | (len(enrolled) >= 1):
                if len(enrolled) == 0: # Default taken to 0 if empty 
                    enrolled = "0"
                if available == "(H)":
                    continue
                else:
                    course_abbr = line[11:15].strip()
                    course_num = line[16:20].strip()
                    
                    # Handle course lab presence
                    course_lab = False
                    if line[21:24].strip() == "LAB" or line[21:24].strip() == "REC":
                        course_lab = True

                    class_section = line[27:29].strip()
                    class_name = line[31:54].strip()
                    class_credits = line[55:58].strip()
                    
                    # Check if credits is correctly formatted
                    if '-' in class_credits:
                        start, end = map(float, class_credits.split('-'))
                        class_credits = int(round((start + end) / 2))
                    else:
                        class_credits = int(float(class_credits))

                    # The times
                    raw_start_time = line[60:64].strip()
                    raw_end_time = line[65:69].strip()
                    isNight = False

                    # Convert the raw times to datetime objects
                    start_time_obj = datetime.strptime(raw_start_time, "%I%M")
                    end_time_obj = datetime.strptime(raw_end_time, "%I%M")

                    # Format the times in the desired HH:MM format
                    start_time = start_time_obj.strftime("%H:%M").replace("00:", "12:")
                    end_time = end_time_obj.strftime("%H:%M").replace("00:", "12:")

                    
                    # Handling night classes
                    isNight = False
                    if (line[69:70].strip() == "N"):
                        isNight = True

                    # Handling days
                    monday = tuesday = wednesday = thursday = friday = False
                    if (line[72] == "M"):
                        monday = True
                    if (line[73] == "T"):
                        tuesday = True
                    if (line[74] == "W"):
                        wednesday = True
                    if (line[75] == "T"):
                        thursday = True
                    if (line[76] == "F"):
                        friday = True

                    # Create a list of days
                    day_list = ['N' if isNight else '', 'M' if monday else '', 'T' if tuesday else '',
                                'W' if wednesday else '', 'TH' if thursday else '', 'F' if friday else '']

                    # Remove empty strings and join the days with a space
                    days = ' '.join(filter(None, day_list)).strip()
                    
                    extraLines = line[77:].strip() # Remove extra lines
                    
                    # Store value of last valid course entry for later use...
                    last_index = i
                    
                    # Dictionaries for course, course meta, and degree audit
                    course = {
                        "dept": course_abbr,
                        "course_number": int(course_num),
                        "course_name": class_name,
                        "credits": class_credits,
                        "start_time": start_time,
                        "end_time": end_time,
                        "days": days,
                    }
                
                    course_meta = {
                        "dept": course['dept'],
                        "course_number": course['course_number'],
                        "prerequisites": [],
                        "lab": course_lab,
                        "Fall Only": False,
                        "Spring Only": False,
                        "workload": int(course['credits'] * 2),
                        "groupProject": False,
                        "attendance_grade": False
                    }
                    
                    degree_audit = {
                        "dept": course['dept'],
                        "course_number": course['course_number'],
                        "complete": False
                    }
                    
                    course_data.append(course)
                    course_meta_data.append(course_meta)
                    degree_audit_data.append(degree_audit)

            else: 
                if line[21:24].strip() == "LAB" or line[21:24].strip() == "REC":
                    # This is a lab or recitation 
                    if last_index is not None:
                        # Update the course meta and degree audit for the last course entry
                        course_meta['lab'] = True

    # Update degree audit data with completed courses
    for course in degree_audit_data:
        if course['course_number'] in completed_course_list:
                course['complete'] = True
                
    # Convert the list of course dictionaries to JSON
    course_data_json = json.dumps(course_data, indent=4)
    course_meta_json = json.dumps(course_meta_data, indent=4)
    degree_audit_json = json.dumps(degree_audit_data, indent=4)

    # Write JSON data to a file for future use
    with open('course_data.json', 'w') as json_file:
        json_file.write(course_data_json)

    with open('course_meta.json', 'w') as json_file:
        json_file.write(course_meta_json)

    with open('degree_audit_data.json', 'w') as json_file:
        json_file.write(degree_audit_json)