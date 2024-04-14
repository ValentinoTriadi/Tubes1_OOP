cmake_minimum_required(VERSION 3.22)
project(Tubes1_OOP)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Automatically include all .cpp files in the src directory
file(GLOB_RECURSE SOURCES "class/*.cpp")

add_executable(Tubes1_OOP ${SOURCES})

# Specify the directories where the compiler should look for include files
target_include_directories(Tubes1_OOP PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})