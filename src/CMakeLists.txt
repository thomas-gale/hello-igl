# include(libigl)
add_executable(main
	main.cpp)

# find_package(libigl CONFIG REQUIRED)
# target_link_libraries(main PRIVATE igl::core igl::common igl::opengl_glfw)
target_link_libraries(main PUBLIC igl::glfw)
