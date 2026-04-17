cmake_minimum_required(VERSION 4.0)
project(until)

set(CMAKE_CXX_STANDARD 20)

add_executable(until main.cpp
        Biblioteca/conductores.hpp
        Biblioteca/infracciones.hpp
        Biblioteca/faltas.hpp
        Biblioteca/AuxiliaryFunctions.cpp
        Biblioteca/AuxiliaryFunctions.hpp)
