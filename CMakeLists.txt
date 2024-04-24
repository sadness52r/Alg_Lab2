cmake_minimum_required(VERSION 3.10...3.27)
project(Alg_Lab2)

file(GLOB all_SRCS "src/*.cpp")
add_executable(main ${all_SRCS})
target_include_directories(main PRIVATE include)