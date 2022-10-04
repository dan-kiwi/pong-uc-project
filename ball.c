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
    
}
