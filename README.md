
# Setup for windows
After 50-60 hours and over a dozen individual attempts to get thing working on windows this is the _only_ video that works
https://www.youtube.com/watch?v=5l3W-brnO7E

Here is the summary:
 1. Download:
    - The GCC 10.3.1 ARM EABI compiler
    - Visual Studio tools
    - Python 3.9+
    - CMake
    - Git

 2. Git Download the `pico-sdk`: https://github.com/raspberrypi/pico-sdk
 3. Go to your computer paths and create a path named `PICO_SDK_PATH` to where the `pico-sdk` was downloaded. E.G., mine is `E:/PiPico/pico-sdk`
 4. Search for `Developer command prompt for VS2019` in the search bar, open it as administrator, and then type in `code` to open VSCode
 5. Once in VSCode, install the CMake Tools and C/C++ plugins, go to the CMake Tools settings and set the `CMake Generator` to `NMake Makefiles`
 6. Verify that `CMake: Configure Environment` is already set to `PICO_SDK_PATH` which should be the path to your `pico-sdk` folder
 7. Close out of VSCode, and reopen it by typing `code` back into the terminal
 8. Once VSCode opens back up, setup your project in the `src/config.h` file, set your compiler in the bottom left of VSCode to `GCC 10.3.1 arm-none-eabi` if not already set, and then click on `Build` right next to it.
 9. Once built, take your Pi Pico, hold down the `BOOTSEL` button while plugging it into your computer and you should see it pop up as a storage device. Now go into the `/build` folder and simply drag over the `j_cassette.uf2` file into the Pico's "drive" and it should start working
 10. Screw around with it and have fun

**NOTE!!!** To compile this ever again you **need to open `Developer command prompt for VS2019` and type `code` for this to work and for your head to not explode**

# Setup for linux users
1. Install windows

# Setup for mac users
1. Refer to the setup for linux users
