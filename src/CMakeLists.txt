cmake_minimum_required (VERSION 2.6)

project(minimaze)

# Set binary output folders
set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Add include directories
include_directories("${PROJECT_SOURCE_DIR}")

# Include all source files into the project
file(GLOB_RECURSE ${PROJECT_NAME}_SRCFILES
   "${PROJECT_SOURCE_DIR}/*.h"
   "${PROJECT_SOURCE_DIR}/*.cpp"
)

# Executable to be produced with required libraries
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCFILES})
target_link_libraries(${PROJECT_NAME} ncurses)

# Requiered compiler features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)