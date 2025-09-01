cmake_minimum_required(VERSION 3.10)

# Define the project name, version, and language
project(block_sandbox VERSION 1.0 LANGUAGES CXX)

# C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# final executable name
set(EXECUTABLE_NAME main)

# Find all .cpp files in src/
file(GLOB SOURCES "src/sources/*.cpp")

# Create executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Compiler flags
target_compile_options(${EXECUTABLE_NAME} PRIVATE -w)

# Include header files
target_include_directories(${EXECUTABLE_NAME} PUBLIC src/headers)

# Find needed libraries
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Link found libraries
target_link_libraries(${EXECUTABLE_NAME} PUBLIC OpenGL::GL OpenGL::GLU GLUT::GLUT)

