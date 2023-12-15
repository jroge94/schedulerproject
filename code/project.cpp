#include "../include/engine.hpp"
// #include "python3.11/Python.h"

int main() {
    DataStore store;
    store.load_all_Data(); 

    std::vector<CourseCatalog> catalogData = store.get_CatalogData();
    std::vector<MetaData> metaData = store.get_MetaData();
    std::vector<DegreeAudit> degreeData = store.get_DegreeData();


    // Set user preferences
    // This is just to demonstrate the recommendation engine
    UserPreferences preferences;
    preferences.set_User("John");
    preferences.set_userWorkload(20);
    preferences.set_userAttendance(3);
    preferences.set_userGroupProjects(3);
    preferences.set_completedCourses({4360, 4402, 4444, 2262, 2362, 2463, 2610, 3102});

    // Create a CourseRecommendationEngine object
    CourseRecommendationEngine engine; 

    // Generate recommendations
    std::vector<CourseCatalog> recommendations = engine.generateRecommendations(
        catalogData,
        metaData,
        degreeData,
        preferences
    );

    // Print recommended courses
    std::cout << "\n\n" << "Recommended Courses: \n";
    for (const auto& course : recommendations) {
        std::cout << course << "\n";
    }
}


    // // Set user preferences
    // UserPreferences preferences;
    // std::string userName;
    // std::string department;
    // std::string semester;
    // int userWorkload;
    // int userLabs;
    // int course;
    // std::vector<int> completedCourses;
    // // Prompt the user for input
    // std::cout << "Enter semester: \n";
    // std::getline(std::cin, semester);   // Use std::getline to read the entire line

    // std::cout << "Enter department: \n";
    // std::getline(std::cin, department);  // Use std::getline to read the entire line

    // std::cout << "Enter user name: \n";
    // std::cin >> userName;

    // std::cout << "Enter desired workload: \n";
    // std::cin >> userWorkload;

    // std::cout << "Enter max number of labs: \n";
    // std::cin >> userLabs;

    // std::cout << semester << " " << department << " " << "\n";

    // std::cout << "Enter completed courses (enter -1 to finish): ";
    // while (std::cin >> course && course != -1) {
    //     completedCourses.push_back(course);
    // }
    // // Set user preferences
    // preferences.set_User(userName);
    // preferences.set_userWorkload(userWorkload);
    // preferences.set_userLabs(userLabs);
    // // preferences.set_userAttendance(userAttendance);
    // // preferences.set_userGroupProjects(userGroupProjects);
    // preferences.set_completedCourses(completedCourses);

    // Py_Initialize();

    // // Add the current working directory to the Python path
    // PyRun_SimpleString("import sys");
    // PyRun_SimpleString("sys.path.append('.')");

    // // Import the module
    // PyObject* pModule = PyImport_ImportModule("generatedata");

    // // Get a reference to the Python function
    // PyObject* pFunction = PyObject_GetAttrString(pModule, "generate_data");

    // // Convert C++ vector to Python list
    // PyObject* pCompletedCourses = PyList_New(completedCourses.size());
    // for (size_t i = 0; i < completedCourses.size(); ++i) {
    //     PyList_SetItem(pCompletedCourses, i, Py_BuildValue("i", completedCourses[i]));
    // }

    // // Create arguments for the Python function
    // PyObject* pArgs = PyTuple_Pack(3,
    //     Py_BuildValue("s", semester.c_str()),
    //     Py_BuildValue("s", department.c_str()), 
    //     pCompletedCourses);

    // if (pArgs == nullptr) {
    //     PyErr_Print();
    //     Py_XDECREF(pFunction);
    //     Py_XDECREF(pModule);
    //     Py_Finalize();
    //     return -1;
    // }
    // // Call the Python function with the arguments
    // PyObject* pValue = PyObject_CallObject(pFunction, pArgs);
    // if (pValue == nullptr) {
    //     PyErr_Print();
    //     Py_XDECREF(pArgs);
    //     Py_XDECREF(pFunction);
    //     Py_XDECREF(pModule);
    //     Py_Finalize();
    //     return -1;
    // }
    // // Process the result if needed

    // // Clean up
    // Py_XDECREF(pValue);
    // Py_XDECREF(pArgs);
    // Py_XDECREF(pFunction);
    // Py_XDECREF(pModule);

    // Py_Finalize();

    // return 0;
