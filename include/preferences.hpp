#ifndef PREFERENCES_HPP
#define PREFERENCES_HPP

#include <string>
#include <vector>

class UserPreferences {  
public:
    
    // Constructors
    UserPreferences() {}

    UserPreferences(
        const std::string& user,
        const std::vector<int>& completed_courses,
        int max_workload, 
        int num_of_group_projects, 
        int attendance_part_of_grade)
        : user_(user), 
        completed_courses_(completed_courses), 
        max_workload_(max_workload), 
        num_of_group_projects_(num_of_group_projects), 
        attendance_part_of_grade_(attendance_part_of_grade) {}

    // Getters
    const std::string& get_User() const { return user_; }
    const std::vector<int>& get_completedCourses() const { return completed_courses_; }
    int get_userWorkload() const { return max_workload_; }
    int get_userGroupProjects() const { return num_of_group_projects_; }
    int get_userAttendance() const { return attendance_part_of_grade_; }

    // Setters
    void set_User(const std::string& user) { user_ = user; }
    void set_completedCourses(const std::vector<int>& completed_courses) { completed_courses_ = completed_courses; }
    void set_userWorkload(int max_workload) { max_workload_ = max_workload; }
    void set_userGroupProjects(int num_of_group_projects) { num_of_group_projects_ = num_of_group_projects; }
    void set_userAttendance(int attendance_part_of_grade) { attendance_part_of_grade_ = attendance_part_of_grade; }

private:
    std::string user_;
    std::vector<int> completed_courses_;
    int max_workload_ = 0; 
    int num_of_group_projects_ = 0; 
    int attendance_part_of_grade_ = 0;
};

#endif // PREFERENCES_HPP
