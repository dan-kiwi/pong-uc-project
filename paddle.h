/*  @file   paddle.h
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong paddle module
 */

#ifndef PADDLE_H
#define PADDLE_H

#include <stdint.h>
#include <stdbool.h>
#include "game.h"

#define START_LEFT 0
#define START_RIGHT 1
#define PADDLE_ROW BOTTOM_MAX

/*
 * Initialises the paddle
 * @param Paddle_t* paddle: pointer to the current players paddle
 */
void paddle_init (Paddle_t* paddle);


/*
 * Moves the paddle by incrementing or decrementing the col value
 * @param Paddle_t* paddle: pointer to the players paddle to be moved
 */
void paddle_move (Paddle_t* paddle);

/*
 * Draws the paddle using the tinygl files
 * @param Paddle_t* paddle: pointer to the current players paddle to be drawn
 */
void paddle_draw (Paddle_t* paddle);

#endif
