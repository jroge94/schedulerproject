# Class Scheduler(better name in the works): An Innovative Solution for Optimal Course Planning
In the complex and often stressful world of academic scheduling, students face numerous challenges that can impact not only their academic performance but also their overall well-being. 
The "Class Scheduler" project is an ambitious initiative aimed at revolutionizing the way students approach course scheduling by addressing critical issues that are often overlooked in traditional scheduling systems.

## Key Challenges Addressed:
Assessing Workload Transparency: One of the core features of this project is to provide clear insights into the expected workload of each class. 
Often, students enroll in courses without a clear understanding of the time and effort required, leading to overwhelming situations. 
Our scheduler will incorporate data on coursework intensity, assignment frequency, and overall time commitment, enabling students to make informed decisions based on their personal schedules and capacities.

## Participation-Based Grading Insight: 
Active participation is a crucial component of many courses, yet its impact on grades isn't always clear at the outset. The Class Scheduler intends to highlight courses where participation significantly influences the final grade. This feature is particularly beneficial for students who may need to balance multiple responsibilities and wish to understand how their engagement in class discussions and activities will be evaluated.

## Mandatory Group Work Evaluation: 
Group assignments are an integral part of the educational experience but can be challenging for those with tight schedules or external commitments. Our scheduler will identify courses with mandatory group work, allowing students to anticipate and plan for the additional coordination and time these activities may require.

## Consideration of Personal Circumstances:
Understanding that each student's situation is unique, the Class Scheduler takes into account personal factors such as:

## Work Commitments: 
Balancing work and study is a reality for many. The scheduler will help in identifying courses that are manageable alongside work commitments, reducing the risk of burnout and academic stress.

## Commuting Constraints: 
For students who commute, time is a precious commodity. The scheduler will prioritize courses with schedules that complement their commuting patterns, potentially reducing travel time and stress.

## Impact on Academic Journey:
The implications of poorly scheduled classes can be far-reaching, from deteriorating grades to the difficult decision of withdrawing from a course. This not only affects academic progress but can also have financial repercussions, particularly concerning financial aid eligibility. By providing a more strategic approach to class scheduling, the Class Scheduler aims to mitigate these risks, fostering a more manageable and successful academic experience.

In conclusion, the Class Scheduler project is more than just a tool; it's a student-centric solution designed to empower students in their academic journey. By providing clarity and foresight in course scheduling, it aspires to enhance the educational experience, ensuring that students can balance their academic, work, and personal life more effectively.

# Course Recommendation Engine: Algorithm Analysis

The algorithm implemented in the `CourseRecommendationEngine` class is a custom design for course recommendation. It integrates various algorithmic principles and doesn't align precisely with any classic algorithm. Below is an analysis of its resemblances:

1. **Filtering and Matching**
   - The algorithm starts by filtering and matching courses based on specific criteria like degree requirements and user preferences. This resembles database querying or search algorithms, where items are filtered according to specific attributes.

2. **Sorting**
   - There is a sorting step that organizes courses based on their workload. This operation is similar to sorting algorithms like QuickSort or MergeSort, though it's specifically applied to a particular attribute of the courses.

3. **Greedy Approach**
   - In generating recommendations, the algorithm adopts a greedy approach, particularly evident when selecting courses based on remaining workload capacity. It chooses the next best option iteratively without reevaluating previous choices, a hallmark of greedy algorithms.

4. **Constraint Satisfaction**
   - The algorithm adheres to various constraints such as workload limits, group project counts, and attendance requirements. This approach is akin to Constraint Satisfaction Problems (CSP), but it doesn't involve backtracking or exploring alternatives as seen in more complex CSPs.

5. **Heuristic-Based Decision Making**
   - Course selection decisions are based on heuristics involving user preferences and course attributes. This strategy is widely used in many algorithms, especially those focusing on optimization and search problems.

## Summary

In essence, the `CourseRecommendationEngine` employs a blend of filtering, matching, sorting, greedy selection, and constraint satisfaction techniques. It's a specialized algorithm developed for the specific challenge of course recommendation, considering a variety of factors and constraints to generate a list of appropriate courses.

## Suggested Improvements
- Greedy approach stacks the higher workload classes for subsequent semesters. It should balance it out. 

## Features missing
- As of 12/14/2023, the workload is completely subjective based on my personal experience with the class. There will need to be a better approach to determing workload for a class. 

