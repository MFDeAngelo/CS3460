cmake_minimum_required(VERSION 3.10)
project(RandomDistributions)

#set(HEADER_FILES header.h)
set(SOURCE_FILES
	Assignment2.cpp)

add_executable(RandDistributions ${SOURCE_FILES})
set_property(TARGET RandDistributions PROPERTY CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(RandDistributions PRIVATE /W4 /WX /permissive-) #/WX
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_compile_options(RandDistributions PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
	message(${CLANG_FORMAT})
	unset(SOURCE_FILES_PATHS)
	foreach(SOURCE_FILE ${SOURCE_FILES})
		get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
		set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
	endforeach()

	add_custom_target(ClangFormat COMMAND ${CLANG_FORMAT} -i -style=file ${SOURCE_FILES_PATHS})

	add_dependencies(RandDistributions ClangFormat)
endif()