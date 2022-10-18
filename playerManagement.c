/*  @file   playerManagement.c
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong player management module
 */

#include "playerManagement.h"
#include "ir_uart.h"
#include "game.h"
#include "ball.h"

#include <stdbool.h>

/*
 * Check's to see if the opponent's computer has started the game
 * @param char received: represents IR info from receiver this cycle
 * @return uint8_t: the gamelevel if game started, 0 else
 */
uint8_t check_player(char received)
{
    if (received == EASY_MODE || received == MEDIUM_MODE || received == HARD_MODE)
        return received;
    return 0;
}

/*
 * Send's the current gamelevel to the opponent. Starts game
 * @param gamelevel: one of three game level's the game will play at
 */
void send_player (uint8_t gamelevel)
{
    ir_uart_putc((char) gamelevel);
}

/*
 * Send the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 * @param Ball_t* ball: represents the address of the ball infomation to send
 * @param bool* player1: representing the address of whether this is player one
 */
void send_ball (Ball_t* ball, bool* player1)
{
    char to_send = (ball->column << 1 | (ball->right & 1));
    ir_uart_putc(to_send);
    ball->row = BALL_OFF_SCREEN;
    *player1 = false;
}

/*
 * Gets the char from the IR receiver
 */
char ir_get_char(void)
{
    char received = 127;
    if (ir_uart_read_ready_p())
        received = ir_uart_getc();
    return received;
}

/*
 * Receives the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 * @param Ball_t* ball: representing the ball to be updated based on received infomation
 * @param bool* player1: representing the address of whether this is player one
 * @param char received: represents IR info from receiver this cycle
 */
void receive_ball (Ball_t* ball, bool* player1, char received)
{
    if (received >= 0 && received <= 15) {
        ball->right = 1 ^ (received & 1);
        ball->column = RIGHT_MAX - (received >> 1);
        ball->row = TOP_MAX;
        ball->forward = false;
        *player1 = true;
        if (ball->column == LEFT_MAX)
            ball->column = LEFT_MAX + 1;
        else if (ball->column == RIGHT_MAX)
            ball->column = RIGHT_MAX - 1;
        else
            ball_move_column(ball);
    }
}
