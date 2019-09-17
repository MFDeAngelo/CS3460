cmake_minimum_required(VERSION 3.10)

project(HelloWorld)

set(HEADER_FILES
	utilities.hpp)

set(SOURCE_FILES
    utilities.cpp
	main.cpp)

add_executable(HelloWorld ${SOURCE_FILES} ${HEADER_FILES})

set_property(TARGET HelloWorld PROPERTY CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(HelloWorld PRIVATE /W4 /permissive-) #/WX
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_compile_options(HelloWorld PRIVATE -Wall -Wextra -pedantic -Werror)
endif()