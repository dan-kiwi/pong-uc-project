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
 */
void paddle_init (Paddle_t* paddle);

/*
 * Moves the paddle by incrementing or decrementing the col value
 */
void paddle_move (Paddle_t* paddle);

/*
 * Draws the paddle using the tinygl files
 */
void paddle_draw (Paddle_t* paddle);

#endif
