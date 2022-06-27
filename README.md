# hello-igl
Experimenting with https://libigl.github.io/tutorial/

## Setup (tested with vscode, arch linux x64)
### Packages
```shell
git submodule update --init --recursive
./lib/vcpkg/bootstrap-vcpkg.sh
./lib/vcpkg/vcpkg install libigl[glfw]
```

### Configure / Build / Run (using `ms-vscode.cmake-tools` vscode extension)
- Command Palette: Cmake:Configure 
- Command Palette: Cmake:Build
- Command Palette: Cmake:Run Without Debugging
 