#include <igl/opengl/glfw/Viewer.h>
#include <igl/opengl/glfw/imgui/ImGuiHelpers.h>
#include <igl/opengl/glfw/imgui/ImGuiMenu.h>
#include <igl/opengl/glfw/imgui/ImGuiPlugin.h>
#include <igl/readOBJ.h>
#include <igl/triangle/triangulate.h>
#include <igl/winding_number.h>
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello IGL" << std::endl;

    // Load non-watertight boundary mesh
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    igl::readOBJ("./resources/bunny.obj", V, F);

    // Generate a simple grid and triangulate it
    // igl::triangle::triangulate()
    // Create the boundary of a square

    // Input polygon
    Eigen::MatrixXd V1;
    Eigen::MatrixXi E1;
    Eigen::MatrixXd H1;
    V1.resize(8, 2);
    E1.resize(8, 2);
    H1.resize(1, 2);

    // create two squares, one with edge length of 4,
    // one with edge length of 2
    // both centered at origin
    V1 << -0.1, -0.1, 0.1, -0.1, 0.1, 0.1, -0.1, 0.1, -0.2, -0.2, 0.2, -0.2,
        0.2, 0.2, -0.2, 0.2;

    // add the edges of the squares
    E1 << 0, 1, 1, 2, 2, 3, 3, 0, 4, 5, 5, 6, 6, 7, 7, 4;

    // specify a point that is inside a closed shape
    // where we do not want triangulation to happen
    H1 << 0, 0;

    // Triangulate the interior
    // a0.005 means that the area of each triangle should
    // not be greater than 0.005
    // q means that no angles will be smaller than 20 degrees
    // for a detailed set of commands please refer to:
    // https://www.cs.cmu.edu/~quake/triangle.switch.html
    // Triangulated interior
    Eigen::MatrixXd V2;
    Eigen::MatrixXi F2;
    igl::triangle::triangulate(V1, E1, H1, "a0.005q", V2, F2);

    // Compute a random winding numbers
    const Eigen::MatrixXd P =
        (Eigen::MatrixXd(2, 3) << 0.01, 0.01, 0.01, 0.02, 0.02, 0.02)
            .finished();
    Eigen::MatrixXd W(2, 1);
    igl::winding_number(V, F, P, W);
    std::cout << "Winding numbers: " << W << std::endl;

    // Plot the mesh
    igl::opengl::glfw::Viewer viewer;

    // Attach a menu plugin
    igl::opengl::glfw::imgui::ImGuiPlugin plugin;
    viewer.plugins.push_back(&plugin);
    igl::opengl::glfw::imgui::ImGuiMenu menu;
    plugin.widgets.push_back(&menu);

    // Draw bunny
    viewer.data().set_mesh(V, F);

    // Draw slice plane
    auto new_id = viewer.append_mesh();
    viewer.data(new_id).set_mesh(V2, F2);

    viewer.launch();
    return 0;
}