/*  @file   welcome.c
    @auther group 219
    @date   October 2022
    @brief  Pong start welcome screen module
 */

#include "communication.h"
#include "tinygl.h"
#include "font3x5_1.h"
#include "navswitch.h"
#include "game.h"

//bool static text_set = false;

/*
 * Initialises the welcome screen with correct settings
 */
void text_init (void)
{
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set(TEXT_SPEED);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_clear();
}

void welcome_screen (void)
{
    text_init();
    tinygl_text("WELCOME TO PONG");
}

bool choose_game_level (uint8_t* gamelevel)
{

    if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
        return true;
    } else if (*gamelevel == GAMELEVEL_NOT_SET) {
        *gamelevel = EASY_MODE;
        display_game_level(*gamelevel);
    } else if (*gamelevel == EASY_MODE) {
        if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            *gamelevel = MEDIUM_MODE;
            display_game_level(*gamelevel);
        }
    } else if (*gamelevel == MEDIUM_MODE) {
        if (navswitch_push_event_p(NAVSWITCH_EAST)) {
            *gamelevel = EASY_MODE;
            display_game_level(*gamelevel);
        } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
            *gamelevel = HARD_MODE;
            display_game_level(*gamelevel);
        }
    } else if (*gamelevel == HARD_MODE) {
        if (navswitch_push_event_p(NAVSWITCH_EAST)) {
            *gamelevel = MEDIUM_MODE;
            display_game_level(*gamelevel);
        }
    }
    return false;
}

void display_game_level (uint8_t gamelevel)
{
    text_init();
    if (gamelevel == EASY_MODE) {
        tinygl_text("EASY");
    } else if (gamelevel == MEDIUM_MODE) {
        tinygl_text("MEDIUM");
    } else {
        tinygl_text("HARD");
    }

}


void lose_screen (void)
{
    text_init();
    tinygl_text("LOST! PUSH TO PLAY AGAIN");
}

void win_screen (void)
{
    text_init();
    tinygl_text("LOST! PUSH TO PLAY AGAIN");
}

//void welcome_new_game_init(void)
//{
//    tinygl_font_set (&font3x5_1);
//    tinygl_text_speed_set(TEXT_SPEED);
//    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
//    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
//    tinygl_text("PUSH TO PLAY AGAIN");
//}
