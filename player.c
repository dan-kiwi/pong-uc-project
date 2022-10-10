//
//  player.c
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//
#include "player.h"
#include "gameButton.h"
#include "ir_uart.h"
#include "ir.h"

#include <stdbool.h>

void set_player(bool* player1)
{
    bool set = false;
    while (set == false) {
        if (game_button_pressed_p > 0) {
            *player1 = true;
            set = true;
            ir_uart_putc("1");
        } else {
            if (ir_player_get() = "1") {
                *player1 = false;
                set = true;
            }
        }
    }
}
