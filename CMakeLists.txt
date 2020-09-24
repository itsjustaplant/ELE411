cmake_minimum_required(VERSION 3.17)
project(ELE411 C)

#https://cmake.org/cmake/help/v3.12/command/string.html
string(TIMESTAMP DATE "%Y%m%d%H%M")
#Valgrind test
add_custom_target(memcheck-report)

#Some compiler flags of standards and optimizations
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Os ")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g -Os ")

#Subdirectories of libs
add_subdirectory(libs/queue)
add_subdirectory(libs/stack)
add_subdirectory(libs/sorting\ algorithms)

#Include directories of header files
include_directories(libs/stack/include/ libs/queue/include/)

#Define executable file
add_executable(main src/main.c)

#Link queue and stack library
target_link_libraries(main queue_lib)
target_link_libraries(main stack_lib)

#Valgrind check command
add_custom_command( TARGET memcheck-report
                    POST_BUILD
                    COMMAND valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --log-file=${CMAKE_BINARY_DIR}/../test/valgrind/valgrind_memcheck_${DATE}.log ${CMAKE_BINARY_DIR}/main
                    DEPENDS libs/stack)
