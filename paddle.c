#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"

#include <stdint.h>
#include <stdbool.h>

#define LEFT_MAX 0
#define RIGHT_MAX 5
#define ROW 1


/* The position of the left of the paddle, with width two */
static uint8_t col = 1;

/*
 * Initialises the paddle
 */
void paddle_init(void)
{

}

/*
 * Moves the paddle by incrementing or decrementing the col value
 */
void paddle_move(void)
{
    if (navswitch_push_event_p (NAVSWITCH_SOUTH) && col != LEFT_MAX)
        col --;

    if (navswitch_push_event_p (NAVSWITCH_NORTH) && col != RIGHT_MAX)
        col++;

}

/*
 * Draws the paddle using the tinygl files
 */
void paddle_draw(void)
{
    tinygl_point_t left = tinygl_point(ROW, col);
    tinygl_point_t right = tinygl_point(ROW, col+1);
    tinygl_draw_line(left, right, true);
}
