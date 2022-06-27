# hello-igl
Experimenting with https://libigl.github.io/tutorial/

## Build / Run
### Pure cmake commands
```shell
mkdir build
cd build
cmake ..
cmake --build .
./src/main
```
### Or using `ms-vscode.cmake-tools` vscode extension) (delete build folder if switching from pure cmake above)
- Command Palette: Cmake:Configure 
- Command Palette: Cmake:Build
- Command Palette: Cmake:Run Without Debugging
 
### Optional vcpkg usage
```shell
git submodule update --init --recursive
./lib/vcpkg/bootstrap-vcpkg.sh
# Note, we are not using libigl vcpkg, but instead using the cmake module in ./cmake (recommended method by libigl folks)
# ./lib/vcpkg/vcpkg install libigl[glfw] 
```