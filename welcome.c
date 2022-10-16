//
// Created by dbi36 on 6/10/22.
//

#include "welcome.h"
#include "tinygl.h"
#include "font3x5_1.h"

/*
 * Initialises the welcome screen with correct settings
 */
void welcome_init (void)
{
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set(10);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text("WELCOME TO PONG");
}


void start_screen (void)
{
   tinygl_update();
}

//uint8_t game_diff (void)
//{
//    return 1;
//}

void welcome_screen (void)
{
    welcome_init();
    start_screen();
}


//void repeat_game_screen(void)
//{
//    do {
//        navswitch_update();
//        tinygl_text("PUSH TO PLAY AGAIN");
//    } while (!(navswitch_push_event_p(NAVSWITCH_PUSH)));
//}
