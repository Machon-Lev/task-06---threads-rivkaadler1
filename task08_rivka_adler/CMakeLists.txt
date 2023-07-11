# CMakeList.txt : CMake project for task08_rivka_adler, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project ("task08_rivka_adler")


set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

# Add source to this project's executable.
add_executable (task08_rivka_adler "")
add_subdirectory (include)
add_subdirectory (src)


# TODO: Add tests and install targets if needed.
