###############################################################################
##     This is part of ex_absfact, an example on how to implement an Abstract
##     Factory pattern. It is a simple textmode game that has two game modes: 
##     Easy and Hard. The Abstract Factory decouples maze creation from the
##     GameObjects required depending on the Game Mode. 
##     This example was used during Videogame Programming lessons at the 
##     Multimedia Degree from the University of Alicante (Spain). You may
##     watch the associated lesson at https:##youtu.be/FFM9cQ2bwA0.
##
##    Copyright (C) 2017   Francisco J. Gallego-Durán
##
##    This program is free software: you can redistribute it and/or modify
##    it under the terms of the GNU General Public License as published by
##    the Free Software Foundation, either version 3 of the License, or
##    (at your option) any later version.
##
##    This program is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU General Public License for more details.
##
##    You should have received a copy of the GNU General Public License
##    along with this program.  If not, see <http:##www.gnu.org/licenses/>.
###############################################################################
cmake_minimum_required (VERSION 3.2)

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