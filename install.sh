#!/bin/bash

# Exit if something fails
set -e

if [[ $(basename "$PWD") !=  "JetBrainsDolphinPlugin"* ]];then
    git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
    cd JetBrainsDolphinPlugin/
fi

mkdir -p build
cd build
cmake -DKDE_INSTALL_QTPLUGINDIR=`kf5-config --qt-plugins` -DCMAKE_BUILD_TYPE=Release  ..
make -j$(nproc)
sudo make install

echo "Installation finished !";
