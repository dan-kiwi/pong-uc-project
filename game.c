#include "system.h"
#include "tinygl.h"
#include "game.h"
#include "navswitch.h"
#include "paddle.h"
#include "pacer.h"
#include "ball.h"
#include "playerManagement.h"
#include "welcome.h"
#include "ir_uart.h"
#include "button.h"

#include <stdint.h>

uint8_t counter;
Ball_t ball;
Paddle_t paddle;
bool player1;
bool win;
bool gameover;

/*
 * Initialises the game by initialising all other files
 */
void init_sys (void)
{
    system_init ();
    tinygl_init(PACER_RATE);
    pacer_init(PACER_RATE);
    navswitch_init();
    ir_uart_init();
    button_init();
    welcome_init();
}

void init_game(void)
{
    counter = 0;
    set_player(&player1);
    paddle_init(&paddle);
    ball_init(&ball, player1);
}

void ballPlayer (void)
{
    ball_draw(&ball);
    if (counter >= 100) {
        counter = 0;
        

        if (check_ball(&ball) && ball.forward) {
            send_ball(&ball, &player1);
//            } else {
//                if (check_if_lost(&ball, paddle)) {
//                    send_loss();
//                    gameover = true;
//                }
        } else {
            ball_move(&ball, paddle);
        }
    
    }
}

void ballOpponent (void)
{
    receive_ball(&ball, &player1);
}

int main (void)
{
    init_sys();
    while (!set_player(&player1)) {
        start_screen();
        pacer_wait();
    }
    init_game();
    
    while (1)
    {
        pacer_wait ();
        navswitch_update ();
        tinygl_clear();

        paddle_move(&paddle);
        paddle_draw(&paddle);

        if (player1 || SINGLE_PLAYER)
            ballPlayer();
        else
            ballOpponent();
//        if (receive_loss()) {
//            win == true;
//            gameover = true;
//        }
        
        tinygl_update ();
        counter++;
//        check_player(&player1, &ball);
        
        //to start a new game
//        if (gameover) {
//            gameover = false;
//
//            repeat_game_screen();
//            set_player(&player1);
//        }
    }
}
