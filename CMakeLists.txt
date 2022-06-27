cmake_minimum_required(VERSION 3.17.2)
project(helloigl
	VERSION 0.1.0
	DESCRIPTION "Experimenting with Libigl"
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/lib/vcpkg/scripts/buildsystems/vcpkg.cmake)

# Libigl
list(PREPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# List of options: https://github.com/libigl/libigl/blob/main/LibiglOptions.cmake.sample
option(LIBIGL_GLFW "Build target igl::glfw" ON)
option(LIBIGL_IMGUI "Build target igl::imgui" ON)
option(LIBIGL_COPYLEFT_TETGEN "Build target igl_copyleft::tetgen" ON)
option(LIBIGL_RESTRICTED_TRIANGLE "Build target igl_restricted::triangle" ON)
include(libigl)

# Main executable
add_executable(main
	src/main.cpp)
target_link_libraries(main PUBLIC igl::glfw igl::imgui igl_copyleft::tetgen igl_restricted::triangle)

# Resources
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
