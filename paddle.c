#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"

#include <stdint.h>

#define LEFT_MAX 0
#define RIGHT_MAX 5

/* The position of the left of the paddle, with width two */
static uint8_t col = 1;

void paddle_init(void)
{
    t
}

void paddle_move(int8_t movement)
{
    if (navswitch_push_event_p (NAVSWITCH_SOUTH) && col != LEFT_MAX)
        col --;

    if (navswitch_push_event_p (NAVSWITCH_NORTH) && col != RIGHT_MAX)
        col++;

}