cmake_minimum_required(VERSION 3.19)

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/vcpkg/scripts/buildsystems/vcpkg.cmake"
CACHE STRING "Vcpkg toolchain file")

project(fall2023-csc3380-project)


set(CMAKE_CXX_STANDARD 20)

enable_testing()
include(CTest)

find_package(nlohmann_json REQUIRED)




## COMMENT OUT FOR TESTING ##
add_executable(project code/project.cpp)
target_include_directories(project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(project PRIVATE nlohmann_json::nlohmann_json)

## COMMENT OUT FOR TESTING ##


## UNCOMMENT FOR TESTING ##
# add_executable(tests tests/tests.cpp)
# target_compile_definitions(tests PRIVATE CATCH_CONFIG_MAIN)
# add_test(NAME tests COMMAND tests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
# target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# target_link_libraries(tests PRIVATE nlohmann_json::nlohmann_json)
## UNCOMMENT FOR TESTING ##


message("VCPKG_ROOT: ${VCPKG_ROOT}")
message("CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")