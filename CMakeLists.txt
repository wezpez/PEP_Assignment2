cmake_minimum_required(VERSION 3.12)
project(assignment20182_wezpez)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment20182_wezpez
        Item.h
        MapOfItems.h
        MapOfItemsTest.cpp
        Stack.h
        )
