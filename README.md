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

### Installation

<details>
<summary><b><b>Required Dependencies</b></b></summary>

<b>Debian/Ubuntu:</b>
```shell
sudo apt install cmake extra-cmake-modules build-essential libkf5kio-dev
```

<b>OpenSUSE:</b>
```shell
sudo zypper install cmake extra-cmake-modules kio-devel
```

<b>Fedora:</b>
```shell
sudo dnf install cmake extra-cmake-modules kf5-kio-devel
```

<b>Arch (Manjaro):</b>
```shell
sudo dnf install cmake extra-cmake-modules kio
```

</details>

<details>
<summary><b>Option A: Build from source using installer script</b></summary>

```shell
curl https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/install.sh | bash
```

</details>

<details>
<summary><b>Option B: Build from source using installer script (without admin privileges)</b></summary>

```shell
curl https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/install-user.sh | bash
```

</details>

<details>
<summary><b>Option C: Install the binaries from the release page</b></summary>

```shell
curl https://raw.githubusercontent.com/alex1701c/JetBrainsDolphinPlugin/master/install-binaries-user.sh | bash
```

</details>


**INFO:** Make sure that you include the jetbrains-api submodule when cloning this repo!
```shell
git clone https://github.com/alex1701c/JetBrainsDolphinPlugin --recurse-submodules
```


<details>
<summary><b>Uninstall</b></summary>

#### Disable Plugin
Go to `Configure Dolphin` ➔ `Services` and then uncheck `JetBrainsDolphinPlugin`
#### Remove Plugin
Run `sudo make uninstall` or `sudo ninja uninstall` from the build directory

</details>
