#!/bin/bash

# This script just copies the binaries/config files from the github release page to the dirs

# Exit if something fails
set -e

# Create folders
mkdir -p build
mkdir -p ~/.local/lib/qt/plugins
mkdir -p ~/.local/share/kservices5
mkdir -p ~/.local/share/pixmaps/

# Add the installation path to the QT_PLUGIN_PATH
if [[ -z "${QT_PLUGIN_PATH}" || "${QT_PLUGIN_PATH}" != *".local/lib/qt/plugins/"* ]]; then
    echo "export QT_PLUGIN_PATH=~/.local/lib/qt/plugins/:$QT_PLUGIN_PATH" >> ~/.bashrc
    export QT_PLUGIN_PATH=~/.local/lib/qt/plugins/:$QT_PLUGIN_PATH
fi

wget $(wget -qO- https://api.github.com/repos/alex1701c/JetBrainsDolphinPlugin/releases/latest \
| grep ".*so" \
| cut -d : -f 2,3 \
| tr -d \" \
| tail -1 ) -O ~/.local/lib/qt/plugins/jetbrainsdolphinplugin.so --max-redirect 1
wget -O ~/.local/share/kservices5/jetbrainsdolphinplugin.desktop\
  https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/src/jetbrainsdolphinplugin.desktop
wget -O ~/.local/share/pixmaps/jetbrains.png\
  https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/src/jetbrains.png

echo "Installation finished !";
