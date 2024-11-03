# JetBrainsDolphinPlugin
This project is a plugin for dolphin which allows you to open directories and associated projects in the Jetbrains IDEs.
If you like this plugin you might want to check out the [KRunner version](https://github.com/alex1701c/JetBrainsRunner).

<details>
<summary><b>Screenshots</b></summary>

#### Submenu for normal folders
![Available CLion projects](https://raw.githubusercontent.com/alex1701c/Screenshots/master/JetBrainsDolphinPlugin/not_a_project.png)

#### Project folder
![Available CLion projects](https://raw.githubusercontent.com/alex1701c/Screenshots/master/JetBrainsDolphinPlugin/clion_project.png)

</details>

## Installation

### Required Dependencies for Dolphin 5

<details>
<summary><b>Debian/Ubuntu</b></summary>

Plasma5:  
```bash install-ubuntu-plasma5
sudo apt install cmake extra-cmake-modules build-essential libkf5kio-dev
```
Plasma6:  
```bash install-ubuntu-plasma6
sudo apt install cmake extra-cmake-modules build-essential libkf6kio-dev
```
  
</details>

<details>
<summary><b>OpenSUSE</b></summary>

Plasma5:  
```bash install-opensuse-plasma5
sudo zypper install cmake extra-cmake-modules kio-devel
```
Plasma6:  
```bash install-opensuse-plasma6
sudo zypper install cmake extra-cmake-modules kf6-kio-devel
```
  
</details>

<details>
<summary><b>Fedora</b></summary>

Plasma5:  
```bash install-fedora-plasma5
sudo dnf install cmake extra-cmake-modules kf5-kio-devel
```
Plasma6:  
```bash install-fedora-plasma6
sudo dnf install cmake extra-cmake-modules kf6-kio-devel
```
  
</details>

<details>
<summary><b>Arch (Manjaro)</b></summary>
  
```shell
sudo pacman -S cmake extra-cmake-modules kio
```
  
</details>

### Installation Methods

#### Option A: Build from source using installer script

```shell
curl https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/install.sh | bash
```

#### Option B: Get it from the [AUR](https://aur.archlinux.org/packages/kf5-servicemenus-jetbrains-dolphin-plugin-git)

**INFO:** Make sure that you include the jetbrains-api submodule when cloning this repo!
```shell
git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
```


### Uninstall

#### Disable Plugin
Go to `Configure Dolphin` ➔ `Services` and then uncheck `JetBrainsDolphinPlugin`
#### Remove Plugin
Run `sudo make uninstall` or `sudo ninja uninstall` from the build directory
