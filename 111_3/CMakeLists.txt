cmake_minimum_required(VERSION 4.0)
project(111_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(111_3 main.cpp
        FuncionesAuxiliares.cpp
        FuncionesAuxiliares.hpp)
target_link_libraries(111_3
${CMAKE_SOURCE_DIR}/lib111_ESTATICA.a)

