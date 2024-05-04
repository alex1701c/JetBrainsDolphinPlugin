#!/usr/bin/env bash

# Exit immediately if something fails
set -e

if [[ $(basename "$PWD") !=  "JetBrainsDolphinPlugin"* ]];then
    # Update existing install
    cd JetBrainsDolphinPlugin/
    git pull --recurse-submodules -f
    echo "Files have been updated."
elif [[ $(basename "$PWD") !=  "JetBrainsDolphinPlugin"* ]]; then
    git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
    cd JetBrainsRunner/
fi

mkdir -p build
cd build

dolphin_version=$(dolphin --version | grep -oP "(?<=dolphin )\d+")
if [[ "$dolphin_version" == "24" ]]; then
    echo "Building for Dolohin6"
    BUILD_QT6_OPTION="-DBUILD_WITH_QT6=ON"
else
    echo "Building for Dolohin6"
    BUILD_QT6_OPTION=""
fi

cmake .. -DCMAKE_BUILD_TYPE=Release -DKDE_INSTALL_USE_QT_SYS_PATHS=ON -DBUILD_TESTING=OFF $BUILD_QT6_OPTION
make -j$(nproc)
echo "The installation into the system wide plugin directory requires superuser privileges"
sudo make install

echo "Installation finished !";
