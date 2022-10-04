#include "tinygl.h"
#include "pacer.h"

void ball_init(void)
{
    
}

void ball_move_forward(//ball)
{
    ball.row++;
    
    if (ball.right) {
        ball.column++;
        
        //ball is at full right side of the board so direction must be flipped
        if (ball.column >= 6) {
            ball.right == false;
        }
    } else {
        ball.column--;
        
        //ball is at full left side of the board so direction must be flipped
        if (ball.column <= 0) {
            ball.right == true;
        }
    }
    
}

void ball_move_back(//ball)
{
    ball.row--;
    
    if (ball.right) {
        ball.column--
        
        //ball is at full right side of the board so direction must be flipped
        if (ball.column <= 0)
            ball.right == false;
        
    } else {
        ball.column++;
        
        //ball is at full left side of the board so direction must be flipped
        if (ball.column >= 6)
            ball.right == true;
        
    }
}

bool ball_at_paddle(ball)
{
    bool at_paddle = false;
    if (ball.row == 0) {
        at_paddle = true;
    }
    return at_paddle;
}

bool ball_to_partner(ball)
{
    bool to_partner = false;
    if (ball.row == 4)
        to_partner = true;
    return to_partner;
}
