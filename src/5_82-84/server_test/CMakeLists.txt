cmake_minimum_required(VERSION 3.5)

set (PrNAME server_tests)
project(${PrNAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add definitions
add_definitions(-fprofile-arcs -ftest-coverage)
# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

find_package( Threads )
include_directories(../../googletests/googletest/include)
include_directories(../server/inc)

set (HEADERS
	tRecursiveParser.h
	tNoRecursiveParser.h
)

set (SOURCE
	tRecursiveParser.cpp
	tNoRecursiveParser.cpp
)

add_executable(
	${PrNAME}
	main.cpp
	${HEADERS}
	${SOURCE}
	)
target_link_libraries(${PrNAME}
	gtest
	gmock
	server
	${CMAKE_THREAD_LIBS_INIT})


