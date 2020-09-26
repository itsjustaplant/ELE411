cmake_minimum_required(VERSION 3.17)
project(ELE411 C)
enable_testing()

#https://cmake.org/cmake/help/v3.12/command/string.html
string(TIMESTAMP DATE "%Y%m%d%H%M")

#Some compiler flags of standards and optimizations
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Os ")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g -Os ")

#Subdirectories of libs
add_subdirectory(libs/queue)
add_subdirectory(libs/stack)
add_subdirectory(tests/valgrind)

#Include directories of header files
include_directories(libs/stack/include/ libs/queue/include/)
#Define executable file
add_executable(main src/main.c)

#Link queue and stack library
target_link_libraries(main queue_lib)
target_link_libraries(main stack_lib)

