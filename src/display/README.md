
# The display

| Filename         | Description                                                   |
|------------------|---------------------------------------------------------------|
| `display_loop.c` | Used to control how the display interacts during real-time use. E.G., on startup load `/screens/home.c` and when you change an oscillator knob, briefly display `/screens/osc.c` before pausing, and returing back home |
| `font.c`         | Used to write text from the hand-written fonts in `font.h` to the display |
| `gfx.c`          | Used to draw circles, rectangles, triangles, n-gons, and variants of them for all of the pages in `/screens` |

# The screens
`/screens` stores all of the pages (screens also used synonymously) used to show info to the user:
 * `home.c` This is the initial screen you see on startup, it shows you your battery life, and the other screens
 * `effects.c` Shows you

| Filename         | Description                                                   |
|------------------|---------------------------------------------------------------|
| `home.c`         | This is the initial screen you see on startup, it shows you your battery life, the list of other screens you can select, and current wave you're playing |
| `osc.c`          | Displays info on the two oscillators, which ones are modulating what, and what each of their waves look like |
| `filter.c`       | Shows you what the filter looks like, pretty simple           |
| `envelope.c`     | Shows a little diagram on what the ADSR looks like            |
| `effects.c`      | Shows some info on the effects you're using                   |
| `presets.c`      | Gives you a list of all the presets you can load, and lets you copy them, and save the configuration you currently have for later |
