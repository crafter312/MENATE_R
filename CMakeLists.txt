# Specify minimum CMake version
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Find the Geant4 package
find_package(Geant4 REQUIRED)

# Find the ROOT package
find_package(ROOT REQUIRED COMPONENTS Hist)

# Define the library name and source files
file(GLOB MENATE_R_SRC *.cc)
add_library(MENATE_R STATIC ${MENATE_R_SRC})

# Include directories for the library
target_include_directories(MENATE_R PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Geant4_INCLUDE_DIRS} ${ROOT_INCLUDE_DIRS})

# Link ROOT and Geant4 libraries
target_link_libraries(MENATE_R ROOT::Hist ${Geant4_LIBRARIES})
