/*  @file   ball.c
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong ball module
 */

#include "ball.h"
#include "game.h"
#include "tinygl.h"
#include <stdbool.h>
#include <stdint.h>

/*
 * Initialisation of the ball. Uses predetermined start points
 */
void ball_init(Ball_t* ball, bool starting)
{
    if (starting) {
        ball->column = COLUMN_START;
        ball->row = ROW_START;
        ball->right = BALL_RIGHT;
        ball->forward = BALL_FORWARD;
    } else {
        ball->column = 10;
        ball->row = 10;
        ball->right = true;
        ball->forward = true;
    }
}

/*
 * Draws the ball on the screen.
 */
void ball_draw (Ball_t* ball)
{
    tinygl_point_t ball_point = tinygl_point(ball->row, ball->column);
    tinygl_draw_point(ball_point, true);
}

void ball_move_row(Ball_t* ball, Paddle_t paddle)
{
    if (ball->forward)
        ball->row--;
    else
        ball->row++;
    if (ball_at_paddle(ball, paddle)) {
        ball->forward = true;
    }
}

void ball_move_column(Ball_t* ball)
{
    if (ball->right) {
        ball->column++;

        //ball is at full right side of the board so direction must be flipped
        if (ball->column >= RIGHT_MAX) {
            ball->right = false;
        }
    } else {
        ball->column--;

        //ball is at full left side of the board so direction must be flipped
        if (ball->column <= LEFT_MAX) {
            ball->right = true;
        }
    }
}

/*
 * Moves the ball based on two boolean variables in Ball_t
 * Also checks if the ball is hitting the paddle. If so, it reverses the direction
 */
void ball_move(Ball_t* ball, Paddle_t paddle)
{
    ball_move_row(ball, paddle);
    ball_move_column(ball);
}

/*
 * Checks if ball is hitting the paddle
 * First checks if ball is the correct row then if the columns match with paddle
 */
bool ball_at_paddle(Ball_t* ball, Paddle_t paddle)
{
    if (ball->row == PADDLE_BOUNCE_ROW) {
        if (ball->column == paddle.left || ball->column == paddle.right)
            return true;
    }
    return false;
}

/*
 * Checks if ball is at the end row
 * Used to check if ball is at end, not at paddle and hence a loss
 */
bool ball_at_end(Ball_t* ball)
{
    if (ball->row == BOTTOM_MAX) {
        return true;
    }
    return false;
}


/*
 * Checks to see if the ball is ready to switch boards
 * If the ball is at the end of the board and returns true
 * if it is to show the player must now change
 */
bool check_ball(Ball_t* ball)
{
    if (ball->row == TOP_MAX)
        return true;
    return false;
}
