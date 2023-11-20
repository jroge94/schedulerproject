# **PLEASE READ!**

## The current required dependencies are:
		"nlohmann-json",
		"python2"
## You can install these dependencies and any other dependencies by:
### Installing vcpkg:

## Follow the instructions from https://github.com/microsoft/vcpkg

### or from https://vcpkg.io/en/getting-started.html

# NOTES:

 I went ahead and reorganized the project folders.
 I made the **main** entry point project.cpp again and created an include folder. 
 ### I went through the code and broke it into 4 separate header files.
	dataclasses.hpp
	datastore.hpp
	engine.hpp
	preferences.hpp



I also created a tests folder and a tests.cpp file in the project folder.

Open the CMakeLists.txt file and follow the instructions there 
if you want to run tests on the header files.

This took up a bit of my time, but it's progress. 