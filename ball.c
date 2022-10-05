#include "ball.h"
#include "game.h"
#include "tinygl.h"
#include "paddle.h"
//#include "pacer.h"


void ball_init(void)
{
    ball.column = 4;
    ball.row = 3;
    ball.right = false;
    ball.forward = false;
}

void ball_draw (void)
{
    tinygl_point_t ball_point = tinygl_point(ball.row, ball.column);
    tinygl_draw_point(ball_point, true);
}

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

}

bool ball_at_paddle(void)
{
    if (ball.row == PADDLE_BOUNCE_ROW) {
        if (ball.column == paddle.left || ball.column == paddle.right)
            return true;
    }
    return false;
}

void hit_ball (void)
{
    if (ball_at_paddle())
        ball.forward = true;
}
//
//bool ball_to_partner(void)
//{
//    bool to_partner = false;
//    if (ball.row == 4)
//        to_partner = true;
//    return to_partner;
//}
