/*  @file   game.h
    @auther group 219
    @date   October 2022
    @brief  Main game module
 */

#ifndef GAME_H
#define GAME_H

#define PACER_RATE 250
#define LEFT_MAX 0
#define RIGHT_MAX 6
#define BOTTOM_MAX 4
#define TOP_MAX 0
#define SINGLE_PLAYER false
#define GAMEMODE_WAITING 0
#define GAMEMODE_PLAY 1
#define GAMEMODE_WIN 2
#define GAMEMODE_LOSS 3
#define GAMEMODE_LEVELSET 4
#define GAMELEVEL_NOT_SET 0
#define EASY_MODE 100
#define MEDIUM_MODE 75
#define HARD_MODE 50

typedef struct {
    uint8_t row;
    uint8_t column;
    bool right;
    bool forward;
} Ball_t;

typedef struct
{
    uint8_t left;
    uint8_t right;
} Paddle_t;

void init_sys (void);

void init_game (void);

#endif
