# Dolphin Service Menu Plugin

This project is a plugin for dolphin which provides service menus.
See https://api.kde.org/frameworks-api/frameworks-apidocs/frameworks/kio/html/classKAbstractFileItemActionPlugin.html for the official docs.

To build this plugin run:
```
mkdir -p build
cd build
cmake ..
# With Makefiles
make -j$(nproc)
sudo make install
# or with ninja
ninja -j$(nproc)
sudo ninja install
```

To create a more optimized release build run instead of
`cmake ..` `cmake -DCMAKE_BUILD_TYPE=Release ..`

The plugin can be disabled in Configure Dolphin -> Services -> uncheck JetBrainsDolphinPlugin 
or uninstalled by running `sudo make uninstall` or `sudo ninja uninstall` from the build directory

You can also build binary packages:
```
cd build
# Make sure that you create a release build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)
cpack -G DEB
cpack -G RPM
```
And you can also build any other package format cpack supports.

### Required Dependencies

Debian/Ubuntu  
`sudo apt install cmake extra-cmake-modules build-essential libkf5kio-dev`

openSUSE  
`sudo zypper install cmake extra-cmake-modules kio-devel`

Fedora  
`sudo dnf install cmake extra-cmake-modules kf5-kio-devel`

Arch(Manjaro):  
`sudo pacman -S cmake extra-cmake-modules kio`  
