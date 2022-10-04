#include "tinygl.h"
#include "pacer.h"

#include <stdint.h>

static uint8_t col = 1;

void paddle_init(void)
{

}

void paddle_move(int8_t movement)
{
    if (movement < 0 && col > 0) {
        col --;
    }
    if (movement > 0 && col < 5) {
        col++;
    }
}