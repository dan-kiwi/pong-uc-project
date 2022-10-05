#ifndef PADDLE_H
#define PADDLE_H

#include <stdint.h>
#include <stdbool.h>
#include "game.h"

#define START_LEFT 1
#define START_RIGHT 2
#define PADDLE_ROW 0

typedef struct
{
    uint8_t left;
    uint8_t right;
} Paddle_t;

Paddle_t paddle;

/*
 * Initialises the paddle
 */
void paddle_init (void);

/*
 * Moves the paddle by incrementing or decrementing the col value
 */
void paddle_move (void);

/*
 * Draws the paddle using the tinygl files
 */
void paddle_draw (void);

/*
 * Checks to see if the ball is colliding with the paddle
 * @param the ball in the game
 * @return boolean whether the ball collides
 */
//bool ball_on_paddle (Ball_t ball);

#endif