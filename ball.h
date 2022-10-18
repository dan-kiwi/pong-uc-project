/*  @file   ball.h
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong ball module
 */

#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include <stdbool.h>
#include "game.h"

#define COLUMN_START LEFT_MAX + 1
#define ROW_START TOP_MAX
#define BALL_RIGHT false
#define BALL_FORWARD false
#define PADDLE_BOUNCE_ROW BOTTOM_MAX - 1

/*
 * Initialisation of the ball. Uses predetermined start points
 * @param Ball_t ball: the address of the ball to be edited for opening coordinates
 * @param bool starting: boolean to represent whether this computer is starting with the ball
 */
void ball_init (Ball_t* ball, bool starting);

/*
 * Draws the ball on the screen.
 * @param Ball_t* ball: the ball position which allows it to be drawn
 */
void ball_draw (Ball_t* ball);

/*
 * Moves the ball column left or right depending on ball.right value
 * @param Ball_t* ball: representing the address of the ball to move
 */
void ball_move_column (Ball_t* ball);

/*
 * Moves the ball based on two boolean variables in Ball_t
 * Also checks if the ball is hitting the paddle. If so, it reverses the direction
 * Uses ball_move_column helper function
 * @param Ball_t* ball: representing the address of the ball to be moved
 * @param Paddle_t paddle: representing the position of the paddle
 */
void ball_move (Ball_t* ball, Paddle_t paddle);

/*
 * Checks if ball is hitting the paddle
 * First checks if ball is the correct row then if the columns match with paddle
 * @param Ball_t* ball: represents the position of the ball
 * @param Paddle_t paddle: representing the position of the paddle
 */
bool ball_at_paddle (Ball_t* ball, Paddle_t paddle);

/*
 * Checks if ball is at the end row
 * Used to check if ball is at end, not at paddle and hence a loss
 * @param Ball_t* ball: represents the position of the ball
 */
bool ball_at_end(Ball_t* ball);

/*
 * Checks to see if the ball is ready to switch boards
 * If the ball is at the end of the board and returns true
 * if it is to show the player must now change
 * @param Ball_t* ball: representing the position of the ball
 */
bool check_ball(Ball_t* ball);

#endif
