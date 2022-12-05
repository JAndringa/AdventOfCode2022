cmake_minimum_required(VERSION 3.22)
project(Day_2_Rock_Paper_Scissors)

set(CMAKE_CXX_STANDARD 14)

add_executable(Day_2_Rock_Paper_Scissors
        main.cpp ../Utils/include/inputReader.hpp ../Utils/src/inputReader.cpp)
