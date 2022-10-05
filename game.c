#include "system.h"
#include "tinygl.h"
#include "game.h"
#include "navswitch.h"
//#include "ir_uart.h"
#include "paddle.h"
#include "pacer.h"
#include "ball.h"

#include <stdint.h>

uint16_t counter = 0;

int main (void)
{
    system_init ();
    tinygl_init(PACER_RATE);
    pacer_init(PACER_RATE);
    navswitch_init();
//    ir_uart_init();
    paddle_init();
    ball_init();


    while (1)
    {
        pacer_wait ();
        navswitch_update ();
        tinygl_clear();

        paddle_move();
        paddle_draw();
        ball_draw();
        if (counter >= 300) {
            counter = 0;
            ball_move();
        }

        tinygl_update ();
        counter++;
    }
}
