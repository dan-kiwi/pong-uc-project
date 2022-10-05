#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t row;
    uint8_t column;
    bool right;
} Ball_t;

Ball_t ball;

#endif