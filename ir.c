//
// Created by dbi36 on 5/10/22.
//

#include "ir.h"
#include "game.h"
#include "ir_uart.h"

void ir_init (void)
{
    ir_uart_init ();
}

void send_ball(Ball_t* ball)
{
    while (!(ir_uart_write_ready_p())) {
        continue;
    }
    ir_uart_putc(ball->column);
    while (!(ir_uart_write_ready_p())) {
        continue;
    }
    ir_uart_putc(ball->row);
}

void receive_ball(Ball_t* ball)
{
    if (ir_uart_read_ready_p()) {
        ball->column = ir_uart_getc();
        while (!(ir_uart_read_ready_p())) {
            continue;
        }
        ball->row = ir_uart_getc();
    }
}