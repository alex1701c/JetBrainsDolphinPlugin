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

### Required Dependencies

<details>
<summary><b>Debian/Ubuntu</b></summary>

```shell
sudo apt install cmake extra-cmake-modules build-essential libkf5kio-dev
```
  
</details>

<details>
<summary><b>OpenSUSE</b></summary>

```shell
sudo zypper install cmake extra-cmake-modules kio-devel
```
  
</details>

<details>
<summary><b>Fedora</b></summary>

```shell
sudo dnf install cmake extra-cmake-modules kf5-kio-devel
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
#### Option B: Build from source using installer script (without admin privileges)

```shell
curl https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/install-user.sh | bash
```

**INFO:** Make sure that you include the jetbrains-api submodule when cloning this repo!
```shell
git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
```


### Uninstall

#### Disable Plugin
Go to `Configure Dolphin` ➔ `Services` and then uncheck `JetBrainsDolphinPlugin`
#### Remove Plugin
Run `sudo make uninstall` or `sudo ninja uninstall` from the build directory
