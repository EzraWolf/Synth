
# UF2 Descriptions

## Note:
When you build this project, the UF2, hex, bin, etc files will be stored until `project_name/build` and not here at `project_name/UF2`

| Filename               | Use                                                   |
|------------------------|-------------------------------------------------------|
| blink.uf2              | Blinks the Picos on-board LED on GPIO 25              |
| PCA9555_input_test.uf2 | On I2C_0, when PORT0_0 is grounded on the PCA9555, it turns the on-board LED at GRPIO25 on, and when PORT0_7 is grounded, the LED is turned back off again. |
