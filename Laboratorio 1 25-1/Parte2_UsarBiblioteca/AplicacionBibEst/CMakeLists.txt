cmake_minimum_required(VERSION 4.1)
project(AplicacionBibEst)

set(CMAKE_CXX_STANDARD 20)

add_executable(AplicacionBibEst main.cpp
        Funciones.cpp)
target_link_libraries(AplicacionBibEst
        ${CMAKE_SOURCE_DIR}/libBiblioteca2025_1_Fuentes.a
)