/*  @file   win.c
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong win checking module
 */

#include "win.h"
#include "ball.h"
#include "ir_uart.h"
#include "game.h"

/*
 * Uses the location of the ball and paddle to determine a loss
 * If the ball is at the bounce row but not the paddle the player has lost
 * and so the func returns true
 */
bool check_if_local_lost(Ball_t* ball, Paddle_t paddle)
{
    if (ball_at_end(ball) && !ball_at_paddle(ball, paddle)) {
        send_loss();
        return true;
    }
    return false;
}


/*
 * Sends the character "L" if player has lost
 */
void send_loss (void)
{
    ir_uart_putc(LOSS_CHAR);
}


/*
 *Checks to see if other player has lost, amd hence this player has won
 */
bool check_if_opponent_lost(char ir_info)
{
    return ir_info == LOSS_CHAR;
}

/*
 * Check's if the game is over
 * Return zero if game not over
 * Return one for local lost
 * Return two for opponent lost
 */
uint8_t check_gameover (Ball_t* ball, Paddle_t paddle, char ir_info)
{
    if (check_if_local_lost(ball, paddle))
        return GAMEMODE_LOSS;
    if (check_if_opponent_lost(ir_info))
        return GAMEMODE_WIN;
    return GAMEMODE_PLAY;
}


