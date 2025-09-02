cmake_minimum_required(VERSION 3.10)

# Define the project name, version, and languages
project(block_sandbox VERSION 1.0 LANGUAGES CXX C)

# C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# final executable name
set(EXECUTABLE_NAME main)

# Find all files in src/
file(GLOB SOURCES "src/sources/*")

# Define the path to your resources
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/src/resources")

# Copy the shaders folder to your build directory
file(COPY "src/resources/shaders" DESTINATION "${CMAKE_BINARY_DIR}")

# Create executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Compiler flags
target_compile_options(${EXECUTABLE_NAME} PRIVATE -w)

# Include header files
target_include_directories(${EXECUTABLE_NAME} PUBLIC src/headers)

# Find needed libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Link found libraries
target_link_libraries(${EXECUTABLE_NAME} PUBLIC OpenGL::GL glfw)

