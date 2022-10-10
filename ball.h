#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include <stdbool.h>
#include "game.h"

#define COLUMN_START 4
#define ROW_START 2
#define BALL_RIGHT false
#define BALL_FORWARD false
#define PADDLE_BOUNCE_ROW BOTTOM_MAX - 1

/*
 * Initialisation of the ball. Uses predetermined start points
 */
void ball_init (Ball_t* ball);

/*
 * Draws the ball on the screen.
 */
void ball_draw (Ball_t* ball);

/*
 * Moves the ball based on two boolean variables in Ball_t
 * Also checks if the ball is hitting the paddle. If so, it reverses the direction
 */
void ball_move (Ball_t* ball, Paddle_t paddle);

/*
 * Checks if ball is hitting the paddle
 * First checks if ball is the correct row then if the columns match with paddle
 */
bool ball_at_paddle (Ball_t* ball, Paddle_t paddle);

/*
 * Checks if ball is ready to move to other player
 */

bool check_ball(Ball_t* ball)

#endif
