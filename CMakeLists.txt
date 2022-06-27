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
option(LIBIGL_GLFW "Build target igl::glfw" ON)
include(libigl)

# Main executable
add_executable(main
	src/main.cpp)
target_link_libraries(main PUBLIC igl::glfw)

# Resources
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
