#include "system.h"
#include "tinygl.h"
#include "game.h"
#include "navswitch.h"
#include "paddle.h"
#include "pacer.h"
#include "ball.h"
//#include "player.h"
//#include "gameButton.h"
#include "welcome.h"

#include <stdint.h>

uint8_t counter;
Ball_t ball;
Paddle_t paddle;
bool player1;
bool win;
bool gameover;

int main (void)
{
    counter = 0;
    system_init ();
    tinygl_init(PACER_RATE);
    pacer_init(PACER_RATE);
    navswitch_init();
    //    ir_uart_init();
    paddle_init(&paddle);
    ball_init(&ball);
//    game_button_init();
    
    welcome_screen();
    
//    set_player(&player1);

//    while (1){
//        tinygl_text("WELCOME TO PONG ");
//        tinygl_update ();
//    }
    
    while (1)
    {
        pacer_wait ();
        navswitch_update ();
        tinygl_clear();
        
        paddle_move(&paddle);
        paddle_draw(&paddle);
        ball_draw(&ball);
        if (counter >= 100) {
            counter = 0;
            ball_move(&ball, paddle);
            
//            if (check_ball(&ball)) {
//                change_player(&player1);
//                send_ball(&ball);
//            } else {
//                if (check_if_lost(&ball, paddle)) {
//                    send_loss();
//                    gameover = true;
//                }
//            }
        }
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
