cmake_minimum_required(VERSION 4.2)
project(probarUntitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(probarUntitled1 main.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Biblioteca")

target_link_libraries(probarUntitled1 PRIVATE Mylibreria)
