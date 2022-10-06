//
// Created by dbi36 on 5/10/22.
//

#include "ir.h"
#include "game.h"
#include "ir_uart.h"

/*
 * Initialises the ir sender/receiver
 */
void ir_init (void)
{
    ir_uart_init ();
}

/*
 * Send the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void send_ball (Ball_t* ball)
{
    char to_send = ball->column << 1 | ball->right;
    ir_uart_putc(to_send);
}

/*
 * Receives the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void receive_ball (Ball_t* ball)
{
    char received;
    if (ir_uart_read_ready_p()) {
        received = ir_uart_getc();
    }
    ball->right = received & 1;
    ball->column = received >> 1;
}