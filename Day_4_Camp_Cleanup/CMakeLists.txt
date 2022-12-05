cmake_minimum_required(VERSION 3.22)
project(Day_4_Camp_Cleanup)

set(CMAKE_CXX_STANDARD 14)

add_executable(Day_4_Camp_Cleanup
        main.cpp ../Utils/include/inputReader.hpp ../Utils/src/inputReader.cpp)
