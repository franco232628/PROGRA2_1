cmake_minimum_required(VERSION 4.0)
project(UnaAplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UnaAplicacionConBibEstatica main.cpp
        FuncionesAuxiliares.cpp
        FuncionesAuxiliares.cpp)
target_link_libraries(UnaAplicacionConBibEstatica
    ${CMAKE_SOURCE_DIR}/libFuentes_Biblioteca.a)
