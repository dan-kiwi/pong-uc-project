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
        if (ball.column >= 6) {
            ball.right == false;
        }
    } else {
        ball.column--;
        if (ball.column)
    }
    
}

void ball_move_back(//ball)
{
    
}
