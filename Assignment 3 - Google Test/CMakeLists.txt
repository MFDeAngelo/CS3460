cmake_minimum_required(VERSION 3.10)
project(RandomDistributions)

set(HEADER_FILES distributions.hpp)
set(SOURCE_FILES
	distributions.cpp
	distributions.hpp)
set(ALL_FILES
	main.cpp
	TestDistributions.cpp
	${SOURCE_FILES}
	${HEADER_FILES})

add_executable(RandDistributions main.cpp ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET RandDistributions PROPERTY CXX_STANDARD 17)

add_executable(UnitTestRunner TestDistributions.cpp ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET UnitTestRunner PROPERTY CXX_STANDARD 17)

set(EXECUTABLES
	UnitTestRunner
	RandDistributions)

foreach(EXECUTABLE ${EXECUTABLES})
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	    target_compile_options(${EXECUTABLE} PRIVATE /W4 /permissive-) #/WX
	elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
		target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -pedantic -Werror)
	endif()
endforeach()

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
	unset(SOURCE_FILES_PATHS)
	foreach(SOURCE_FILE ${ALL_FILES})
		get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
		set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
	endforeach()

	add_custom_target(ClangFormat COMMAND ${CLANG_FORMAT} -i -style=file ${SOURCE_FILES_PATHS})

	add_dependencies(RandDistributions ClangFormat)
endif()