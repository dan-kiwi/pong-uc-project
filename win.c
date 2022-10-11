//
//  win.c
//  
//
//  Created by Bethany Kaye-Blake on 11/10/22.
//

#include "win.h"
#include "ball.h"
#include "ir_uart.h"

/*
 * Uses the location of the ball and paddle to determine a loss
 * If the ball is at the bounce row but not the paddle the player has lost
 * and so the func returns true
 */
bool check_if_lost(Ball_t* ball, Paddle_t paddle)
{
    if (ball_at_bounce_row(ball, paddle) == true && ball_at_paddle(ball) == false) {
        return true;
    }
    return false;
}


/*
 * Sends the character "L" if player has lost
 */
void send_loss()
{
    char loss = "L";
    ir_uart_putc(loss);
}


/*
 *Checks to see if other player has lost, amd hence this player has won
 */
bool receive_loss()
{
    if (ir_uart_read_ready_p()) {
        char received = ir_uart_getc();
    }
    if (received == "L") {
        return true;
    }
    return false;
}

