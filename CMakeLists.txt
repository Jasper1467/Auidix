cmake_minimum_required(VERSION 3.27)
project(Audix)

set(CMAKE_CXX_STANDARD 20)

add_library(Audix SHARED library.cpp
        Utilities/Types.h
        Utilities/CSafety.cpp
        Utilities/CSafety.h
        Utilities/CAudioDevice.cpp
        Utilities/CAudioDevice.h)
