cmake_minimum_required(VERSION 4.1)
project(AppBibEst)

set(CMAKE_CXX_STANDARD 20)

add_executable(AppBibEst main.cpp
        FuncionesAux.cpp)
target_link_libraries(AppBibEst
        ${CMAKE_SOURCE_DIR}/libBibCompilada.a
)