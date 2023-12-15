cmake_minimum_required(VERSION 3.19)

# Set the toolchain file provided by vcpkg before the project declaration
set(CMAKE_TOOLCHAIN_FILE "C:/Workspace/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

project(schedulerproject)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
include(CTest)

# Find the nlohmann_json package
find_package(nlohmann_json REQUIRED)

## COMMENT OUT FOR TESTING ##
add_executable(schedulerproject code/project.cpp)

# Link nlohmann_json to your project
target_link_libraries(schedulerproject PRIVATE nlohmann_json::nlohmann_json)


## COMMENT OUT FOR TESTING ##


## UNCOMMENT FOR TESTING ##
# add_executable(tests tests/tests.cpp)
# target_compile_definitions(tests PRIVATE CATCH_CONFIG_MAIN)
# add_test(NAME tests COMMAND tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
# target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(tests PRIVATE nlohmann_json::nlohmann_json)
## UNCOMMENT FOR TESTING ##
