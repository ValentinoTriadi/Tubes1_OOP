cmake_minimum_required(VERSION 3.22)
project(Tubes1_OOP)

set(CMAKE_CXX_STANDARD 17)

# Add the compiler flags
if(MSVC)
    add_compile_options(/W4 /WX)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Automatically include all .cpp files in the src directory
file(GLOB_RECURSE SOURCES "class/*.cpp" "main.cpp")

add_executable(Tubes1_OOP ${SOURCES}
        main.cpp)

# Specify the directories where the compiler should look for include files
target_include_directories(Tubes1_OOP PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})