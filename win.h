/*  @file   win.h
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong win checking module
 */

#ifndef win_h
#define win_h

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "game.h"

#define LOSS_CHAR 25

/*
 * Uses the location of the ball and paddle to determine a loss
 * If the ball is at the bounce row but not the paddle the player has lost
 * and so the func returns true
 * @param Ball_t* ball: address of the ball to be checked
 * @param Paddle_t paddle: player paddle to be used to check
 * @return bool: true if player has lost, false if still in play
 */
bool check_if_local_lost(Ball_t* ball, Paddle_t paddle);


/*
 * Sends the character "L" if player has lost
 */
void send_loss(void);


/*
 * Checks to see if other player has lost, amd hence this player has won
 * @param char received: represents IR info from receiver this cycle
 * @return bool: true if opponent has lost, else return false
 */
bool check_if_opponent_lost(char ir_info);

/*
 * Check's if the game is over
 * @param Ball_t* ball: address of the ball to be checked
 * @param Paddle_t paddle: player paddle to be used to check
 * @param char received: represents IR info from receiver this cycle
 * @return uint8_t: zero if game not over, one for local lost, two for opponent lost
 */
uint8_t check_gameover (Ball_t* ball, Paddle_t paddle, char ir_info);

#endif /* win_h */
