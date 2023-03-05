
# The hardware interfaces
These files are mostly just here to make it easier to connect to the chips with some higher-level functions. Many of the initializations for these chips are in `main.c` but a lot of their functions are handled by the files that need them the most.

E.G., the `PCA9555 IO expander` is almost entirely used by the `keys.c` file, aside from some odd cases such as the `display/screens/presets.c` file using the keyboard to help you name the presets.

| Filename         | Interface | Description                                                   |
|------------------|-----------|---------------------------------------------------------------|
| `PCA9555.c`      | I2C_0     | 16 pin IO expander primarily used by `keys.c` to act as a piano keyboard |
| `PCM5102.c`      | SPI_0     | Has exclusive access to SPI_0. **NO** other chip is allowed to use it because it makes SPI_0 act more like an I2S interface, and has specific PIO for it. Has no specific file where it's used the most, but `oscillator.c` and `main.c` use it a lot |
| `ST7789V2.c`     | SPI_1     | Interface for the 170x320 pixel display, graphics are handled in `display/gfx.c` and fonts are handled in `display/font.c` but actual screens displayed are in `display/screens/*.c` |
| `W25Q16.c`       | SPI_1     | 2MB flash storage chip mostly used to load and store presets, but also other information such as total runtime, total keys pressed, and settings preferences |
