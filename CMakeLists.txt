cmake_minimum_required(VERSION 3.19)
project(Hospital)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hospital
        date.h
        heure.h
        "infirmier .h"
        main.cpp
        Medcin.h
        service.h)
