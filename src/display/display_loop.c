
#include <stdint.h>

// Local
#include "display/display_loop.h"

/**
 * @name display_loop_exec
 * @date 05-Mar-23
 * 
 * @brief Manages the constant loop that displays the different screens,
 * initializes on the home screen, and changes screens based on which knobs
 * and buttons are pressed.
 * E.G., when a knob from the oscillators are changed, it'll show the `osc.c`
 * screen, pause for a moment, and then return back to home
 * 
 * @return void
 */
void display_loop_exec() {

}

/**
 * @name display_loop_load_screen
 * @date 05-Mar-23
 * 
 * @brief Loads the different pre-made screens. Each screen has a number
 * associated with it in `display_loop.h` loosely based off of how often
 * it'll appear
 * 
 * @param 
 * @return void
 */
void display_loop_load_screen(uint8_t screen) {

}
