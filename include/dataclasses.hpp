#ifndef DATACLASSES_HPP
#define DATACLASSES_HPP

#include <string>
#include <vector>
#include <iostream>



class CourseCatalog {
public:
    std::string dept;
    int course_number;
    std::string course_name;
    int credits;
    std::string start_time;
    std::string end_time;
    std::string days;
    CourseCatalog(
		std::string dept, 
		int course_number,
		std::string course_name, 
		int credits,
        std::string start_time, 
		std::string end_time,
		std::string days)
        : dept(dept), course_number(course_number), course_name(course_name),
        credits(credits), start_time(start_time), end_time(end_time), days(days) {}

	CourseCatalog getCourseCatalogData() {
	return CourseCatalog(dept, course_number, course_name, credits, start_time, end_time, days);}

    // Getters
    std::string getDept() const { return dept; }
    int getCourseNumber() const { return course_number; }
    std::string getCourseName() const { return course_name; }
    int getCredits() const { return credits; }
    std::string getStartTime() const { return start_time; }
    std::string getEndTime() const { return end_time; }
    std::string getDays() const { return days; }
    
    // Setters
    void setDept(const std::string& dept) { this->dept = dept; }
    void setCourseNumber(int course_number) { this->course_number = course_number; }
    void setCourseName(const std::string& course_name) { this->course_name = course_name; }
    void setCredits(int credits) { this->credits = credits; }
    void setStartTime(const std::string& start_time) { this->start_time = start_time; }
    void setEndTime(const std::string& end_time) { this->end_time = end_time; }
    void setDays(const std::string& days) { this->days = days; }

    friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& course) {
        os << "Dept: " << course.getDept() << "|CourseNumber: " << course.getCourseNumber()
            << "|CourseName: " << course.getCourseName() << "|Credits: " << course.getCredits()
            << "|Start Time: " << course.getStartTime() << "|End Time: " << course.getEndTime()
            << "|Days: " << course.getDays() << "\n";
            return os;}

    // Comparison operators for CourseCatalog objects
    bool operator==(const CourseCatalog& other) const {
        return course_number == other.course_number &&
            start_time == other.start_time &&
            end_time == other.end_time;}
};

class MetaData {
public:
    std::string dept;
    int course_number;
    std::vector<int> prerequisites;
    bool fallOnly;
    bool springOnly;
    int workload;
    bool groupProject;
    bool attendanceGrade;
    MetaData(
        std::string dept,
        int course_number,
        std::vector<int> prerequisites,
        bool fallOnly,
        bool springOnly,
        int workload,
        bool groupProject,
        bool attendanceGrade)
        : dept(dept), course_number(course_number), prerequisites(prerequisites),
        fallOnly(fallOnly), springOnly(springOnly), workload(workload), 
        groupProject(groupProject), attendanceGrade(attendanceGrade) {}

    MetaData getMetaData() {
        return MetaData(dept, course_number, prerequisites, fallOnly, springOnly, workload, groupProject, attendanceGrade);}	
    //Getters
    std::string getDept() const { return dept; }
    int getMetaCourseNumber() const { return course_number; }
    std::vector<int> getPrerequisites() const { return prerequisites; }
    bool getFallOnly() const { return fallOnly; }
    bool getSpringOnly() const { return springOnly; }
    int getWorkload() const { return workload; }
    bool getGroupProject() const { return groupProject; }
    bool getAttendance() const { return attendanceGrade; }

    //Setters
    void setMetaDept( std::string& dept) { this->dept = dept; }
    void setMetaCourseNumber(int course_number) { this->course_number = course_number; }
    void setMetaPrerequisites( std::vector<int>& prerequisites) { this->prerequisites = prerequisites; }
    void setMetaFallOnly() { this->fallOnly = true; }
    void setMetaSpringOnly() { this->springOnly = true; }
    void setMetaWorkload(int workload) { this->workload = workload; }
    void setMetaGroupProject() { this->groupProject = true; }
    void setMetaAttendanceGrade() { this->attendanceGrade = true; }

    friend std::ostream& operator<<(std::ostream& os, const MetaData& metaData) {
        os << "Dept: " << metaData.getDept() << "|Course Number: " << metaData.getMetaCourseNumber()
        << "|Prerequisites: [" ;

    const auto& prerequisites = metaData.getPrerequisites();
        for (size_t i = 0; i < prerequisites.size(); ++i) {
            os << prerequisites[i];
            if (i < prerequisites.size() - 1) {
                os << ", ";}}
    
        os << "]|Fall Only: " << (metaData.getFallOnly() ? "Yes" : "No")
            << "|Spring Only: " << (metaData.getSpringOnly() ? "Yes" : "No")
            << "|Workload: " << metaData.getWorkload()
            << "|Group Project: " << (metaData.getGroupProject() ? "Yes" : "No")
            << "|Attendance Grade: " << (metaData.getAttendance() ? "Yes" : "No")
            << "\n";
        return os;}

	void print() {
		std::cout << *this;
	}
};

class DegreeAudit {
public:
    std::string dept;
    int course_number;
    bool iscomplete;
    DegreeAudit(
        std::string dept, 
        int course_number, 
        bool iscomplete): dept(dept), course_number(course_number), iscomplete(iscomplete) {}

    DegreeAudit getDegreeAudit() {
        return DegreeAudit(dept, course_number, iscomplete);
    }
    //Getters
    std::string getDegreeAuditDept() const { return dept; }
    int getDegreeAuditNumber() const { return course_number; }
    bool isComplete()  { return iscomplete; }

    //Setters
    void setDegreeAuditDept(const std::string& dept) { this->dept = dept; }
    void setDegreeAuditNumber(int course_number) { this->course_number = course_number; }
    void markComplete(int courseNum) {
        if (this->course_number == courseNum) {
            this->iscomplete = true;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, DegreeAudit degreeAudit) {
        os << "Dept: " << degreeAudit.getDegreeAuditDept() << "|Course Number: " << degreeAudit.getDegreeAuditNumber()
            << "|Is Complete: " << (degreeAudit.isComplete() ? "Yes" : "No") << "\n";
            return os;}

	void print() {
		std::cout << *this;
	}

    bool operator==( DegreeAudit other) const {
        return dept == other.dept &&
            course_number == other.course_number &&
            iscomplete == other.iscomplete;
    }

};



#endif