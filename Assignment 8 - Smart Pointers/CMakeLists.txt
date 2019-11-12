cmake_minimum_required(VERSION 3.10)
project(SharedPTR)

set(HEADER_FILES shared_ptr.hpp)
set(ALL_FILES
	main.cpp
	TestMemory.cpp
	${HEADER_FILES})

add_executable(Memory main.cpp ${HEADER_FILES})
set_property(TARGET Memory PROPERTY CXX_STANDARD 17)

add_executable(UnitTestRunner TestMemory.cpp ${HEADER_FILES})
set_property(TARGET UnitTestRunner PROPERTY CXX_STANDARD 17)

set(EXECUTABLES
	UnitTestRunner
	Memory)

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

	add_dependencies(Memory ClangFormat)
endif()




configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(UnitTestRunner gtest_main)
