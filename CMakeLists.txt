cmake_minimum_required(VERSION 2.6)
project(sfmlopengltemplae)

add_executable(sfmlopengltemplae main.cpp)

install(TARGETS sfmlopengltemplae RUNTIME DESTINATION bin)
