# © Joseph Cameron 2017. All rights reserved.
cmake_minimum_required (VERSION 3.0)

message(STATUS "GDK is now building...")

#Setup GDK project
project (GDK)
set (GDK_VERSION_MAJOR 1)
set (GDK_VERSION_MINOR 0)

#Collect the source code
set (SOURCEROOT ../source/)
include_directories(${SOURCEROOT})

add_library(GDK ${SOURCEROOT}Math/Plane.cpp)