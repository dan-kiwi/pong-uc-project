//
//  player.c
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//
#include "playerManagement.h"
#include "ir_uart.h"
#include "button.h"

#include <stdbool.h>


/*
 * Player1 is set by the first board to push the Button
 * When the button is pushed, that board set player1
 * to true and sends over IR that the other board
 * is now not player1
 */
bool set_player(bool* player1)
{
    bool set = false;
    button_update();
    if (button_push_event_p(0) > 0) {
        *player1 = true;
        set = true;
        ir_uart_putc(STARTING_NUMBER);
    } else {
        char get_player = ir_get_char();
        if (get_player == STARTING_NUMBER) {
            *player1 = false;
            set = true;
        }
    }
    return set;
}



/*
 * Send the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void send_ball (Ball_t* ball, bool* player1)
{
    char to_send = ball->column << 1 | ball->right;
    ir_uart_putc(to_send);
    *player1 = false;
}

char ir_get_char(void)
{
    char received = 0;
    if (ir_uart_read_ready_p()) {
        received = ir_uart_getc();
    }
    return received;
}

/*
 * Receives the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void receive_ball (Ball_t* ball, bool* player1)
{
    char received = ir_get_char();
    if (received) {
        ball->right = received & 1;
        ball->column = received >> 1;
        *player1 = true;
    }
}
