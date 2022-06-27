#include <igl/opengl/glfw/Viewer.h>
#include <igl/readOBJ.h>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello IGL" << std::endl;

    // Load mesh
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::readOBJ("./resources/bunny.obj", V, F);

    // Plot the mesh
    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(V, F);
    viewer.launch();

    return 0;
}