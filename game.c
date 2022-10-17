/*  @file   game.c
    @auther group 219
    @date   October 2022
    @brief  Main game module
 */

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
#include "win.h"

#include <stdint.h>

uint8_t counter;
Ball_t ball;
Paddle_t paddle;
bool player1;
uint8_t gamemode;
uint8_t gamelevel;

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
    gamemode = GAMEMODE_WELCOME;
    gamelevel = GAMELEVEL_NOT_SET;
}

/*
 * Initialises the game to play
 */
void init_game(void)
{
    paddle_init(&paddle);
    ball_init(&ball, player1);
    counter = 0;

}

/*
 * Method called when the ball is on this computer
 */
void ballPlayer (void)
{
    ball_draw(&ball);
    if (counter >= gamelevel) {
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

/*
 * Method called when ball is on opponent's computer
 */
void ballOpponent (void)
{
    receive_ball(&ball, &player1);
    ball_draw(&ball);
}

/*
 * Main game function
 */
int main (void)
{
    init_sys();
    
    while (1)
    {
        pacer_wait ();
        navswitch_update ();
        if (gamemode == GAMEMODE_WELCOME) {
            if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
                gamemode = GAMEMODE_LEVELSET;
            }
        } else if (gamemode == GAMEMODE_LEVELSET) {
            if (choose_game_level(&gamelevel)) {
                gamemode = GAMEMODE_PLAY;
                player1 = true;
                set_player(&player1);
                init_game();
            }
        } else if (gamemode == GAMEMODE_PLAY) {
            tinygl_clear();
            paddle_move(&paddle);
            paddle_draw(&paddle);

            if (player1 || SINGLE_PLAYER)
                ballPlayer();
            else {
                ballOpponent();
                counter = 0;
            }
        } else if (gamemode == GAMEMODE_LOSS) {

        }

//        uint8_t gameover = check_gameover(&ball, paddle);
//        if (gameover == 1) {
//            win = false;
//            gameover = true;
//        } else if (gameover == 2) {
//            win = true;
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
