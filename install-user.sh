#!/bin/bash

# Exit if something fails
set -e

if [[ $(basename "$PWD") !=  "JetBrainsDolphinPlugin"* ]];then
    git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
    cd JetBrainsDolphinPlugin/
fi

# Create folders
mkdir -p build
mkdir -p ~/.local/lib/qt/plugins
mkdir -p ~/.local/share/kservices5
mkdir -p ~/.local/share/pixmaps/

cd build

# Add the installation path to the QT_PLUGIN_PATH
if [[ -z "${QT_PLUGIN_PATH}" || "${QT_PLUGIN_PATH}" != *".local/lib/qt/plugins/"* ]]; then
    echo "export QT_PLUGIN_PATH=~/.local/lib/qt/plugins/:$QT_PLUGIN_PATH" >> ~/.bashrc
    export QT_PLUGIN_PATH=~/.local/lib/qt/plugins/:$QT_PLUGIN_PATH
fi

cmake -DKDE_INSTALL_QTPLUGINDIR="~/.local/lib/qt/plugins" -DKDE_INSTALL_KSERVICES5DIR="~/.local/share/kservices5" -DJETBRAINS_ICON_INSTALL_DIR="~/.local/share/pixmaps/" -DCMAKE_BUILD_TYPE=Release  ..
make -j$(nproc)
make install

echo "Installation finished !";
