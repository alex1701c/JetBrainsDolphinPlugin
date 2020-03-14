# Dolphin Service Menu Plugin

This project is a plugin for dolphin which allows you to open directories and 
associated projects in the Jetbrains IDEs.  
If you like this plugin you might want to check out the KRunner version: https://github.com/alex1701c/JetBrainsRunner.

To install this project you can use the deb/rpm packages from the Release page on Github or build from source:
```
git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
cd JetBrainsDolphinPlugin 
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DKDE_INSTALL_QTPLUGINDIR=`kf5-config --qt-plugins` ..
make -j$(nproc)
sudo make install
```

The plugin can be disabled in Configure Dolphin -> Services -> uncheck JetBrainsDolphinPlugin 
or uninstalled by running `sudo make uninstall` or `sudo ninja uninstall` from the build directory

### Required Dependencies

Debian/Ubuntu  
`sudo apt install cmake extra-cmake-modules build-essential libkf5kio-dev`

openSUSE  
`sudo zypper install cmake extra-cmake-modules kio-devel`

Fedora  
`sudo dnf install cmake extra-cmake-modules kf5-kio-devel`

Arch(Manjaro):  
`sudo pacman -S cmake extra-cmake-modules kio`  

### Screenshots

#### Submenu for normal folders
![Available CLion projects](https://raw.githubusercontent.com/alex1701c/Screenshots/master/JetBrainsDolphinPlugin/not_a_project.png)

#### Project folder
![Available CLion projects](https://raw.githubusercontent.com/alex1701c/Screenshots/master/JetBrainsDolphinPlugin/clion_project.png)
