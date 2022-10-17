/*  @file   playerManagement.h
    @auther group 219
    @date   October 2022
    @brief  Pong player management module
 */

#ifndef player_h
#define player_h

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "game.h"

#define BALL_OFF_SCREEN 10

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

uint8_t check_player (void);

void send_player (uint8_t gamelevel);

#endif /* player_h */
