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
 
## Notes, setup (tested with vscode, arch linux x64)
### Packages
```shell
git submodule update --init --recursive
./lib/vcpkg/bootstrap-vcpkg.sh
# ./lib/vcpkg/vcpkg install libigl[glfw]
```