//
//  win.h
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//

#ifndef win_h
#define win_h

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "game.h"

#define LOSS_CHAR 'L'

/*
 * Uses the location of the ball and paddle to determine a loss
 * If the ball is at the bounce row but not the paddle the player has lost
 * and so the func returns true
 */
bool check_if_local_lost(Ball_t* ball, Paddle_t paddle);


/*
 * Sends the character "L" if player has lost
 */
void send_loss(void);


/*
 *Checks to see if other player has lost, amd hence this player has won
 */
bool check_if_opponent_lost(void);

/*
 * Check's if the game is over
 * Return zero if game not over
 * Return one for local lost
 * Return two for opponent lost
 */
uint8_t check_gameover (Ball_t* ball, Paddle_t paddle);

#endif /* win_h */
