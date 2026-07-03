cmake_minimum_required(VERSION 3.25)
project(AccuratePercent VERSION 1.0.0 LANGUAGES CXX)
find_package(Geode REQUIRED)
add_geode_mod(
    darkgamer91111hue.accuratepercent
    VERSION 1.0.0
    SOURCES src/main.cpp
)
