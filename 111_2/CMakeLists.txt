cmake_minimum_required(VERSION 4.0)
project(111_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(111_2 main.cpp)
target_link_libraries(111_2
${CMAKE_SOURCE_DIR}/lib111_ESTATICA.a)
