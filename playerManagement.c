/*  @file   playerManagement.c
    @auther group 219
    @date   October 2022
    @brief  Pong player management module
 */

#include "playerManagement.h"
#include "ir_uart.h"
#include "button.h"

#include <stdbool.h>



bool check_player(void)
{
    return ir_get_char() == STARTING_NUMBER;
}

void send_player (void)
{
    ir_uart_putc(STARTING_NUMBER);
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
    ball->row = BALL_OFF_SCREEN;
    *player1 = false;
}

/*
 * Gets the char from the IR receiver
 */
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
        ball->right = ~(received & 1);
        ball->column = RIGHT_MAX - (received >> 1);
        ball->row = TOP_MAX;
        ball->forward = false;
        *player1 = true;
//        if (ball->right) {
//            ball->column++;
//
//            //ball is at full right side of the board so direction must be flipped
//            if (ball->column >= RIGHT_MAX) {
//                ball->right = false;
//            }
//        } else {
//            ball->column--;
//
//            //ball is at full left side of the board so direction must be flipped
//            if (ball->column <= LEFT_MAX) {
//                ball->right = true;
//            }
//        }
    }
}
