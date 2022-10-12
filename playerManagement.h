//
//  player.h
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include <stdbool.h>
#include "game.h"

#define STARTING_NUMBER 1

/*
 * Player1 is set by the first board to push the Button
 * When the button is pushed, that board set player1
 * to true and sends over IR that the other board
 * is now not player1
 */
bool set_player(bool* player1);

/*
 * Send the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void send_ball (Ball_t* ball, bool* player1);

/*
 * Receives the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void receive_ball (Ball_t* ball, bool* player1);

char ir_get_char (void);

#endif /* player_h */
