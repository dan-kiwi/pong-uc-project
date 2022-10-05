#ifndef BALL_H
#define BALL_H

#include <stdint.h>
#include <stdbool.h>

#define PADDLE_BOUNCE_ROW PADDLE_ROW - 1
#define COLUMN_START 4
#define ROW_START 1
#define BALL_RIGHT false
#define BALL_FORWARD false

typedef struct {
    uint8_t row;
    uint8_t column;
    bool right;
    bool forward;
} Ball_t;

Ball_t ball;

/*
 * Initialisation of the ball. Uses predetermined start points
 */
void ball_init (void);

/*
 * Draws the ball on the screen.
 */
void ball_draw (void);

/*
 * Moves the ball based on two boolean variables in Ball_t
 * Also checks if the ball is hitting the paddle. If so, it reverses the direction
 */
void ball_move (void);

/*
 * Checks if ball is hitting the paddle
 * First checks if ball is the correct row then if the columns match with paddle
 */
bool ball_at_paddle (void);

#endif