/*  @file   playerManagement.h
    @auther group 219
    @date   October 2022
    @brief  Pong player management module
 */

#ifndef player_h
#define player_h

#include <stdio.h>
#include <stdbool.h>
#include "game.h"

#define STARTING_NUMBER 1
#define BALL_OFF_SCREEN 10
#define BUTTON_0 0

bool check_player (void);

void send_player (void);

/*
 * Send the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void send_ball (Ball_t* ball, bool* player1);

/*
 * Receives the information of the ball through IR
 * The LSB is whether the ball if traveling right
 * The next three LSB's are the ball's column 0-6
 */
void receive_ball (Ball_t* ball, bool* player1);

/*
 * Gets the char from the IR receiver
 */
char ir_get_char (void);

#endif /* player_h */
