/*  @file   welcome.h
    @auther group 219
    @date   October 2022
    @brief  Pong start welcome screen module
 */
#ifndef WELCOME_H
#define WELCOME_H

#include <stdint.h>

#define EASY_MODE 100
#define MEDIUM_MODE 75
#define HARD_MODE 50
#define TEXT_SPEED 10

void welcome_init (void);

void start_screen (void);

//uint8_t game_diff (void);

void welcome_screen (void);

//void repeat_game_screen(void);

#endif //WELCOME_H
