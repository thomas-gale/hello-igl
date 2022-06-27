# hello-igl
Experimenting with https://libigl.github.io/tutorial/

## Setup (testing on VSCode, Arch Linux x64)
```shell
git submodule update --init --recursive
./lib/vcpkg/bootstrap-vcpkg.sh
./lib/vcpkg/vcpkg install libigl[glfw]
```