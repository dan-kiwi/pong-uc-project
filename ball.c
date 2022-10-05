#include "ball.h"
#include "game.h"
#include "tinygl.h"
#include "paddle.h"
//#include "pacer.h"

/*
 * Initialisation of the ball. Uses predetermined start points
 */
void ball_init(void)
{
    ball.column = COLUMN_START;
    ball.row = ROW_START;
    ball.right = BALL_RIGHT;
    ball.forward = BALL_FORWARD;
}

/*
 * Draws the ball on the screen.
 */
void ball_draw (void)
{
    tinygl_point_t ball_point = tinygl_point(ball.row, ball.column);
    tinygl_draw_point(ball_point, true);
}

/*
 * Moves the ball based on two boolean variables in Ball_t
 * Also checks if the ball is hitting the paddle. If so, it reverses the direction
 */
void ball_move(void)
{
    if (ball.forward)
        ball.row++;
    else
        ball.row--;

    if (ball.right) {
        ball.column++;

        //ball is at full right side of the board so direction must be flipped
        if (ball.column >= RIGHT_MAX) {
            ball.right = false;
        }
    } else {
        ball.column--;

        //ball is at full left side of the board so direction must be flipped
        if (ball.column <= LEFT_MAX) {
            ball.right = true;
        }
    }
    if (ball_at_paddle()) {
        ball.forward = true;
    }

}

/*
 * Checks if ball is hitting the paddle
 * First checks if ball is the correct row then if the columns match with paddle
 */
bool ball_at_paddle(void)
{
    if (ball.row == PADDLE_BOUNCE_ROW) {
        if (ball.column == paddle.left || ball.column == paddle.right)
            return true;
    }
    return false;
}

//
//bool ball_to_partner(void)
//{
//    bool to_partner = false;
//    if (ball.row == 4)
//        to_partner = true;
//    return to_partner;
//}
