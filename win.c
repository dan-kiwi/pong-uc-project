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
 * @param Ball_t* ball: address of the ball to be checked
 * @param Paddle_t paddle: player paddle to be used to check
 * @return bool: true if player has lost, false if still in play
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
 * Sends the character LOSS_CHAR if player has lost
 */
void send_loss (void)
{
    if (ir_uart_write_ready_p())
        ir_uart_putc(LOSS_CHAR);
}


/*
 * Checks to see if other player has lost, amd hence this player has won
 * @param char received: represents IR info from receiver this cycle
 * @return bool: true if opponent has lost, else return false
 */
bool check_if_opponent_lost(char ir_info)
{
    return ir_info == LOSS_CHAR;
}

/*
 * Check's if the game is over
 * @param Ball_t* ball: address of the ball to be checked
 * @param Paddle_t paddle: player paddle to be used to check
 * @param char received: represents IR info from receiver this cycle
 * @return uint8_t: zero if game not over, one for local lost, two for opponent lost
 */
uint8_t check_gameover (Ball_t* ball, Paddle_t paddle, char ir_info)
{
    if (check_if_local_lost(ball, paddle))
        return GAMEMODE_LOSS;
    if (check_if_opponent_lost(ir_info))
        return GAMEMODE_WIN;
    return GAMEMODE_PLAY;
}


