#include "paddle.h"
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "game.h"

#include <stdint.h>
#include <stdbool.h>

/*
 * Initialises the paddle
 */
void paddle_init (void)
{
    paddle.left = START_LEFT;
    paddle.right = START_RIGHT;
    paddle_draw();
}

/*
 * Moves the paddle by incrementing or decrementing the col value
 */
void paddle_move (void)
{
    if (navswitch_push_event_p (NAVSWITCH_SOUTH) && paddle.right != RIGHT_MAX) {
        paddle.left++;
        paddle.right++;
    }

    if (navswitch_push_event_p (NAVSWITCH_NORTH) && paddle.left != LEFT_MAX) {
        paddle.left--;
        paddle.right--;
    }
}

/*
 * Draws the paddle using the tinygl files
 */
void paddle_draw (void)
{
    tinygl_point_t left = tinygl_point(PADDLE_ROW, paddle.left);
    tinygl_point_t right = tinygl_point(PADDLE_ROW, paddle.right);
    tinygl_draw_line(left, right, true);
}
