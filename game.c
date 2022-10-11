#include "system.h"
#include "tinygl.h"
#include "game.h"
#include "navswitch.h"
#include "paddle.h"
#include "pacer.h"
#include "ball.h"
#include "player.h"
#include "gameButton.h"
#include "welcome.h"

#include <stdint.h>

uint16_t counter = 0;
uint16_t to_count = 100;

Ball_t ball;
Paddle_t paddle;
bool player1;
bool win = false;
bool game_end = false;

int main (void)
{
    system_init ();
    tinygl_init(PACER_RATE);
    pacer_init(PACER_RATE);
    navswitch_init();
//    ir_uart_init();
    paddle_init(&paddle);
    ball_init(&ball);
    game_button_init();

    welcome_screen();

    set_player(&player1);
    
    while (1)
    {
        pacer_wait ();
        navswitch_update ();
        tinygl_clear();

        paddle_move(&paddle);
        paddle_draw(&paddle);
        ball_draw(&ball);
        if (counter >= to_count && player1) {
            counter = 0;
            if (to_count > 0) {
                to_count--;
            }
            ball_move(&ball, paddle);

            if (check_ball(&ball)) {
                change_player(&player1);
                send_ball(&ball);
            } else {
                if (check_if_lost(&ball, paddle)) {
                    send_loss();
                    game_end = true;
                }
            }
        }
        if (receive_loss()) {
            win == true;
            game_end = true;
        }
        tinygl_update ();
        counter++;
        check_player(&player1, &ball);


        //to start a new game
        if (game_end) {
            game_end = false;
            
            repeat_game_screen();
            set_player(&player1);
        }
    }
}
