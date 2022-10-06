//
// Created by dbi36 on 5/10/22.
//

#include "game.h"

#ifndef IR_H
#define IR_H

/*
 * Initialises the ir sender/receiver
 */
void ir_init (void);

/*
 * Send the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void send_ball (Ball_t* ball);

/*
 * Receives the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void receive_ball (Ball_t* ball);

#endif //IR_H
