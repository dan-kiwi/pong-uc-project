#ifndef GAME_H
#define GAME_H

#define PACER_RATE 250
#define LEFT_MAX 0
#define RIGHT_MAX 6
#define BOTTOM_MAX 4
#define TOP_MAX 0
#define SINGLE_PLAYER true

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

#endif