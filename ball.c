#include "ball.h"
//#include "game.h"
#include "tinygl.h"
//#include "pacer.h"

void ball_init(void)
{
    ball.column = 0;
    ball.row = 0;
    ball.right = true;
}

void ball_draw (void)
{
    tinygl_point_t ball_point = tinygl_point(ball.column, ball.row);
    tinygl_draw_point(ball_point, true);
}

//void ball_move_forward(void)
//{
//    ball.row++;
//
//    if (ball.right) {
//        ball.column++;
//
//        //ball is at full right side of the board so direction must be flipped
//        if (ball.column >= RIGHT_MAX) {
//            ball.right == false;
//        }
//    } else {
//        ball.column--;
//
//        //ball is at full left side of the board so direction must be flipped
//        if (ball.column <= LEFT_MAX) {
//            ball.right == true;
//        }
//    }
//
//}
//
//void ball_move_back(void)
//{
//    ball.row--;
//
//    if (ball.right) {
//        ball.column--;
//
//        //ball is at full right side of the board so direction must be flipped
//        if (ball.column <= 0)
//            ball.right == false;
//
//    } else {
//        ball.column++;
//
//        //ball is at full left side of the board so direction must be flipped
//        if (ball.column >= 6)
//            ball.right == true;
//
//    }
//}
//
//bool ball_at_paddle(void)
//{
//    bool at_paddle = false;
//    if (ball.row == 0) {
//        at_paddle = true;
//    }
//    return at_paddle;
//}
//
//bool ball_to_partner(void)
//{
//    bool to_partner = false;
//    if (ball.row == 4)
//        to_partner = true;
//    return to_partner;
//}
