#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include <stdbool.h>

#define PADDLE_BOUNCE_ROW 1

typedef struct {
    uint8_t row;
    uint8_t column;
    bool right;
    bool forward;
} Ball_t;

Ball_t ball;

void ball_init (void);

void ball_draw (void);

void ball_move (void);

void hit_ball (void);

#endif