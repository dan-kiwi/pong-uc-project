/*  @file   game.c
    @author Daniel Bishop & Bethany Kaye-Blake
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
#include "communication.h"
#include "ir_uart.h"
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
    welcome_screen();
    gamemode = GAMEMODE_WAITING;
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
    gamemode = GAMEMODE_PLAY;
}

/*
 * Method called when the ball is on this computer
 */
void ballPlayer ()
{
    ball_draw(&ball);
    if (counter >= gamelevel) {
        counter = 0;
        
        if (check_ball(&ball) && ball.forward)
            send_ball(&ball, &player1);
        else
            ball_move(&ball, paddle);
    }
}

/*
 * Method called when ball is on opponent's computer
 * @param char received: represents IR info from receiver this cycle
 */
void ballOpponent (char ir_info)
{
    receive_ball(&ball, &player1, ir_info);
    ball_draw(&ball);
    counter = 0;
}

/*
 * Main game function
 * The main cycles through checking for each gamemode.
 * Different lines execute based on what gamemode variable is equal to
 */
int main (void)
{
    char ir_info;
    init_sys();

    while (1)
    {
        ir_info = ir_get_char(); //gets the IR receiver info to pass through to functions
        uint8_t opponentStart = check_player(ir_info); // check's if opponent computer has started
        if (gamemode == GAMEMODE_PLAY) { //main gameplay function
            tinygl_clear();
            paddle_move(&paddle);
            paddle_draw(&paddle);
            
            if (player1)
                ballPlayer();
            else
                ballOpponent(ir_info);
            
            gamemode = check_gameover(&ball, paddle, ir_info);
            
        } else if (opponentStart) { //called when opponent has started
            gamelevel = opponentStart;
            player1 = false;
            init_game();
            
        } else if (gamemode == GAMEMODE_WAITING) { //waiting to start game
            if (navswitch_push_event_p(NAVSWITCH_PUSH))
                gamemode = GAMEMODE_LEVELSET;
            
        } else if (gamemode == GAMEMODE_LEVELSET) { //setting level of game
            if (choose_game_level(&gamelevel)) {
                player1 = true;
                send_player(gamelevel);
                init_game();
            }
            
        } else if (gamemode == GAMEMODE_LOSS) { //when local computer has lost
            lose_screen();
            gamemode = GAMEMODE_WAITING;
            gamelevel = GAMELEVEL_NOT_SET;
            
        } else if (gamemode == GAMEMODE_WIN) { //when local computer has won
            win_screen();
            gamemode = GAMEMODE_WAITING;
            gamelevel = GAMELEVEL_NOT_SET;
        }
        
        pacer_wait();
        navswitch_update();
        tinygl_update();
        counter++;
    }
}
