cmake_minimum_required(VERSION 3.17)
project(ELE411 C)

#https://cmake.org/cmake/help/v3.12/command/string.html
string(TIMESTAMP DATE "%Y%m%d%H%M")

add_custom_target(memcheck-report)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Os ")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -g -Os ")

add_executable(stack src/main.c stack/src/stack.c stack/include/stack.h queue/src/queue.c queue/include/queue.h include/sort_algorithms.c include/sort_algorithms.h)
add_custom_command( TARGET memcheck-report
                    POST_BUILD
                    COMMAND valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes --log-file=${CMAKE_BINARY_DIR}/valgrind_memcheck_${DATE}.log ./stack
                    DEPENDS ./stack)
