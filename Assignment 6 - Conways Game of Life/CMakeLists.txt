cmake_minimum_required(VERSION 3.10)
project(ConwaysLife)

set(HEADER_FILES 
	LifeSimulator.hpp
	Pattern.hpp
	PatternAcorn.hpp
	PatternBlinker.hpp
	PatternBlock.hpp
	PatternGlider.hpp
	PatternGosperGliderGun.hpp
	RenderConsole.hpp
	Renderer.hpp
	rlutil.h)

set(SOURCE_FILES
	LifeSimulator.cpp
	main.cpp
	PatternAcorn.cpp
	PatternBlinker.cpp
	PatternBlock.cpp
	PatternGlider.cpp
	PatternGosperGliderGun.cpp
	RenderConsole.cpp)


set(ALL_FILES
	${SOURCE_FILES}
	${HEADER_FILES})

add_executable(ConwaysLife ${SOURCE_FILES} ${HEADER_FILES})
set_property(TARGET ConwaysLife PROPERTY CXX_STANDARD 17)




if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_compile_options(ConwaysLife PRIVATE /W4 /permissive-) #/WX
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_compile_options(ConwaysLife PRIVATE -Wall -Wextra -pedantic -Werror)
endif()



find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
	unset(SOURCE_FILES_PATHS)
	foreach(SOURCE_FILE ${ALL_FILES})
		get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
		set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
	endforeach()

	add_custom_target(ClangFormat COMMAND ${CLANG_FORMAT} -i -style=file ${SOURCE_FILES_PATHS})

	add_dependencies(ConwaysLife ClangFormat)
endif()



