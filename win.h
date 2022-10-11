//
//  win.h
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//

#ifndef win_h
#define win_h

#include <stdio.h>

/*
 * Uses the location of the ball and paddle to determine a loss
 * If the ball is at the bounce row but not the paddle the player has lost
 * and so the func returns true
 */
bool check_if_lost(Ball_t* ball, Paddle_t paddle);


/*
 * Sends the character "L" if player has lost
 */
void send_loss();


/*
 *Checks to see if other player has lost, amd hence this player has won
 */
bool receive_loss();

#endif /* win_h */
