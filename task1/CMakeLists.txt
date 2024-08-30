cmake_minimum_required(VERSION 3.16.5)
set (PROJECT_NAME task1)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)

add_executable("${PROJECT_NAME}" main.cpp)

file(COPY "input.txt" DESTINATION "/")
