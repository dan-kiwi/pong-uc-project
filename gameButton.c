//
//  gameButton.c
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//

#include "gameButton.h"
#include "button.h"

/*Initialises button1*/
void game_button_init(void)
{
    button_init();
}

/*Returns a non-zero int if button is pressed*/
int game_button_pressed_p(void)
{
    int pressed = 0;
    if (PIND ) {
        pressed = 1;
    }
    return pressed;
}
