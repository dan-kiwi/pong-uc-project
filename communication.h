/*  @file   welcome.h
    @author group 219
    @date   October 2022
    @brief  Pong start welcome screen module
 */
#ifndef WELCOME_H
#define WELCOME_H

#include <stdint.h>
#include <stdbool.h>

#define TEXT_SPEED 10

void text_init (void);

void welcome_screen (void);

bool choose_game_level (uint8_t* gamelevel);

void display_game_level (uint8_t gamelevel);

void lose_screen (void);

void win_screen (void);

#endif //WELCOME_H
