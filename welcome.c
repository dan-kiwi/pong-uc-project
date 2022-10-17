/*  @file   welcome.c
    @auther group 219
    @date   October 2022
    @brief  Pong start welcome screen module
 */

#include "welcome.h"
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

void welcome_init (void)
{
    text_init();
    tinygl_text("WELCOME TO PONG");
//    text_set = true;
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
//    switch (gamelevel) {
//        case EASY_MODE:
//            tinygl_text("EASY");
//            break;
//        case MEDIUM_MODE:
//            tinygl_text("MEDIUM");
//            break;
//        case HARD_MODE:
//            tinygl_text("HARD");
//            break;
//    }
    if (gamelevel == EASY_MODE) {
        tinygl_text("EASY");
    } else if (gamelevel == MEDIUM_MODE) {
        tinygl_text("MEDIUM");
    } else {
        tinygl_text("HARD");
    }

}
//
//
//void start_screen (uint8_t* gamemode, uint8_t* gamelevel)
//{
//   if (!text_set) {
//       welcome_init();
//   } else if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
//       *gamemode = GAMEMODE_PLAY;
//       text_set = false;
//   }
//}

//uint8_t game_diff (void)
//{
//    return 1;
//}

//void welcome_screen (void)
//{
//    welcome_init();
//    start_screen();
//}

//void welcome_new_game_init(void)
//{
//    tinygl_font_set (&font3x5_1);
//    tinygl_text_speed_set(TEXT_SPEED);
//    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
//    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
//    tinygl_text("PUSH TO PLAY AGAIN");
//}
