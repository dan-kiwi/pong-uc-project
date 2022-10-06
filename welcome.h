//
// Created by dbi36 on 6/10/22.
//

#ifndef WELCOME_H
#define WELCOME_H

#include <stdint.h>

#define EASY_MODE 100
#define MEDIUM_MODE 75
#define HARD_MODE 50

void welcome_init (void);

void start_screen (void);

uint8_t game_diff (void);

void welcome_screen (void);

#endif //WELCOME_H