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

/*
 * Player1 is set by the first board to push the Button
 * When the button is pushed, that board set player1
 * to true and sends over IR that the other board
 * is now not player1
 */
void set_player(bool* player1);


/*
 * Updates player1 and alerts other board through IR
 * By sending "C" for change the other board knows it
 * is now player 1
 */
void change_player(bool* player1);


/*
 * Checks to see if the other board is changing player
 * If "C" is received, for change, the other board has
 * updated to not be player 1, and now the current board is
 * At this point the board also receives the ball
 */
void check_player(bool* player1, Ball_t* ball);

#endif /* player_h */
