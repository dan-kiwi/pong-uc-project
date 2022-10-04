#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t row,
    uint8_t col,
    bool right
} Ball_t;

#endif