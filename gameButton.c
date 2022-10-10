//
//  gameButton.c
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//

#include "gameButton.h"
#include <avr/io.h>

/*Initialises button1*/
void game_button_init(void)
{
    DDRD &= ~(1<<7);
}

/*Returns a non-zero int if button is pressed*/
int game_button_pressed_p(void)
{
    /* TODO.  */
    int pressed = 0;
    if (PIND &= (1<<7)) {
        pressed = 1;
    }
    return pressed;
}
