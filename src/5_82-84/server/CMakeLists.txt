cmake_minimum_required(VERSION 3.5)

project(server LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
#set(CMAKE_C_FLAGS "-g -O0 --coverage -fprofile-arcs -ftest-coverage")

# add definitions
add_definitions(-fprofile-arcs -ftest-coverage)
# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

find_package( Threads )
include_directories(./inc)
set (HEADERS
	inc/item.h
	inc/node.h
	inc/aparser.h
	inc/recursiveParser.h
	inc/noRecursiveParser.h
)

set (SOURCE
	src/item.cpp
	src/node.cpp
	src/aparser.cpp
	src/recursiveParser.cpp
	src/noRecursiveParser.cpp
)

add_library(server ${HEADERS} ${SOURCE} )
target_link_libraries( server ${CMAKE_THREAD_LIBS_INIT} )
add_executable(run_server main.cpp )
target_link_libraries(run_server server ${CMAKE_THREAD_LIBS_INIT} )
