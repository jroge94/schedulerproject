#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "dataclasses.hpp"
#include "preferences.hpp"
#include "datastore.hpp"
#include <algorithm>
#include <vector>


/**************************CLASS COURSE RECOMMENDATION ENGINE*****************************************/
/*
    The Course Recommendation Engine is responsible for generating recommendations based on the user's preference
*/

class CourseRecommendationEngine {
public:
    std::vector<CourseCatalog> recommendedCourses;

    CourseRecommendationEngine() {}

    // Helper function to add a new course to the recommended courses
    void addRecommendedCourse(CourseCatalog& course) {
        recommendedCourses.push_back(course);
    }

    bool isCourseNumberInDegreeData(const std::vector<DegreeAudit>& degreeData, int courseNumber) {
        for (const auto& audit : degreeData) {
            if (audit.getDegreeAuditNumber() == courseNumber) {
                return true;
            }
        }
        return false;
    }

    void updateDegreeData(std::vector<DegreeAudit>& degreeData, const std::vector<int>& completedCourses) {
        for (auto& audit : degreeData) {
            if (std::find(completedCourses.begin(), completedCourses.end(), audit.getDegreeAuditNumber()) != completedCourses.end()) {
                audit.markComplete(audit.getDegreeAuditNumber());
            }
        }
    }

    std::vector<DegreeAudit> filterIncompleteDegreeData( std::vector<DegreeAudit>& degreeData) {
        std::vector<DegreeAudit> remainingCourses;
        for (auto& audit : degreeData) {
            if (!audit.isComplete()) {
                remainingCourses.push_back(audit);
            }
        }
        return remainingCourses;
    }

    std::vector<CourseCatalog> generateRecommendations(
        std::vector<CourseCatalog>& catalog_Data,
        std::vector<MetaData>& meta_Data,
        std::vector<DegreeAudit>& degree_Data,
        UserPreferences& userPreferences
    ) {
        // Step 1: Update the degree audit data based on user preferences
        updateDegreeData(degree_Data, userPreferences.get_completedCourses());

        // Step 2: Filter out the incomplete degree data
        auto remainingCourses = filterIncompleteDegreeData(degree_Data);

        // Step 3: Filter out meta data that doesn't match remaining courses
        std::vector<MetaData> remainingMeta;
        for (auto& metaCourse : meta_Data) {
            if (isCourseNumberInDegreeData(remainingCourses, metaCourse.getMetaCourseNumber())) {
                remainingMeta.push_back(metaCourse);
            }
        }

        // Step 4: Filter out catalog data that doesn't match remaining courses
        std::vector<CourseCatalog> remainingCatalog;
        for (auto& catalogCourse : catalog_Data) {
            if (isCourseNumberInDegreeData(remainingCourses, catalogCourse.getCourseNumber())) {
                remainingCatalog.push_back(catalogCourse);
            }
        }

    // Step 5: Sort remainingMeta based on the following criteria
    //  Workload low to high

    std::sort(remainingMeta.begin(), remainingMeta.end(), [](MetaData& a, MetaData& b) {
        return a.getWorkload() < b.getWorkload();
    });
    // Step 7: Initialize variables
    int groupProjectCount = 0;
    int attendanceCount = 0;
    int workloadMax = userPreferences.get_userWorkload();
    int attendanceMax = userPreferences.get_userAttendance();

    
    
    
    //This should be initialized as a vector of CourseCatalog objects not integers
    //It needs to inherit the members of the CourseCatalog class
    // const std::vector<CourseCatalog> recommendedCourses;

    std::cout << "\n\n";
    std::cout << "The Recommendation Engine is Running..." << std::endl;
    std::cout << "workload Maximum: " << workloadMax << std::endl;
    
    // Step 8: For each metaCourse in remainingMeta
    for ( auto& metaCourse : remainingMeta) {
        // Step 9: For each catalogCourse in remainingCatalog
        for ( auto& catalogCourse : remainingCatalog) {
            // Step 10: If the meta data course number matches the catalog course number
            // and if the course is not already in the recommendedCourses vector
            // and if the there are no time conflicts
            // deduct the workload value from the max workload value
            // and if the workload value is greater than or equal to 0 then add the course to the recommendedCourses vector
            
    
            if (metaCourse.getMetaCourseNumber() == catalogCourse.getCourseNumber()) {
                if (!std::any_of(recommendedCourses.begin(), recommendedCourses.end(), [&](CourseCatalog& course) {
                    return course.getCourseNumber() == metaCourse.getMetaCourseNumber();
                })) {
                    std::cout << "Checking Course Number: " << metaCourse.getMetaCourseNumber() << std::endl;
                    workloadMax -= metaCourse.getWorkload();
                    if (workloadMax >= 0) {
                        std::cout << "Adding Course Number: " << metaCourse.getMetaCourseNumber() << std::endl;
                        recommendedCourses.push_back(catalogCourse);
                        // Increment counters for group projects and attendance
                        if (metaCourse.getGroupProject() == true) {
                            groupProjectCount++;
                        }
                        if (metaCourse.getAttendance() == true) {
                            attendanceCount++;
                        }
            std::cout << "WorkLoad left: " << workloadMax << std::endl;
            std::cout << "Group Project Count: " << groupProjectCount << std::endl;
            std::cout << "Attendance Count: " << attendanceCount << std::endl;
                    }
                }
        }
    
    
    }
}
return recommendedCourses;


}

};
#endif