
# Note:
This is an ongoing project and errors _will_ occur just to spite you.
Currently, a few exist that basically mean nothing and are nearly unreplicatable. For VSCODE, `The current language mode is incompatible` is a favorite, and it effects a grand total of... nothing. Just disable it.

# Features
| Feature                          | State | Desccription                                    |
-----------------------------------|-------|-------------------------------------------------|
| Key press recognition            | DONE  | Use the PCA9555 to read key presses             |
| Velocity sensitive keys          | TODO  | Read the resistance on a velostat film          |
| 32b Audio out                    | TODO  | Use the PCM5102 to output 32b mono audio        |
| Dynamic waveform calculation     | TODO  | Dynamically calculate the wave its outputting   |
| LP, BP, and HP filters           | TODO  | Add low-pass, band-pass, and high-pass filters  |
| ASDR Envelope                    | TODO  | Add an envelope to help modulate the sound      |
| Delay, reverb, and other effects | TODO  | Add various sound-fx to make it sound cooler-er |
| MIDI in / out                    | TODO  | Use the on-chip USB port or MIDI port for MIDI  |
| TFT display out                  | TODO  | Use the ST7789V2 to show 170x320 res pages      |
| Loading and saving presets       | TODO  | Load and save presets via the W25Q16 flash chip |

# Setup for windows
After 50-60 hours and over a dozen individual attempts to get thing working on windows [this is the _only_ video that works](https://www.youtube.com/watch?v=5l3W-brnO7E)

Here is the summary:
 1. Download:
    - The GCC 10.3.1 ARM EABI compiler
    - Visual Studio tools
    - Python 3.9+
    - CMake
    - Git

 2. Git Download the [`pico-sdk`](https://github.com/raspberrypi/pico-sdk)
 3. Go to your computer paths and create a path named `PICO_SDK_PATH` to where the `pico-sdk` was downloaded. E.G., mine is `E:/PiPico/pico-sdk`
 4. Search for `Developer command prompt for VS2019` in the search bar, open it as administrator, and then type in `code` to open VSCode
 5. Once in VSCode, install the CMake Tools and C/C++ plugins, go to the CMake Tools settings and set the `CMake Generator` to `NMake Makefiles`
 6. Verify that `CMake: Configure Environment` is already set to `PICO_SDK_PATH` which should be the path to your `pico-sdk` folder
 7. Close out of VSCode, and reopen it by typing `code` back into the terminal
 8. Once VSCode opens back up, setup your project in the `src/config.h` file, set your compiler in the bottom left of VSCode to `GCC 10.3.1 arm-none-eabi` if not already set, and then click on `Build` right next to it.
 9. Once built, take your Pi Pico, hold down the `BOOTSEL` button while plugging it into your computer and you should see it pop up as a storage device. Now go into the `/build` folder and simply drag over the `j_cassette.uf2` file into the Pico's "drive" and it should start working
 10. Screw around with it and have fun

**NOTE!!!** To compile this ever again you **need to open `Developer command prompt for VS2019` as an administrator and type `code` for this to work**

# Setup for linux users
1. Install windows

# Setup for mac users
1. Refer to the setup for linux users
