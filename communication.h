/*  @file   welcome.h
    @author Daniel Bishop & Bethany Kaye-Blake
    @date   October 2022
    @brief  Pong start welcome screen module
 */
#ifndef WELCOME_H
#define WELCOME_H

#include <stdint.h>
#include <stdbool.h>

#define TEXT_SPEED 10

/*
 * Initialises the screen with the correct text settings
 */
void text_init (void);

/*
 * Sets welcome text
 */
void welcome_screen (void);

/*
 * Set's the game level for the pong game based on user input from navswitch
 * If gamelevel changes, display_game_level() is called to update screen
 * @param &gamelevel: takes address of gamelevel and updates it
 * @return bool: if game level has been selected true, else false
 */
bool choose_game_level (uint8_t* gamelevel);

/*
 * Takes a given gamelevel and displays the game level on screen
 * @param gamelevel: an int which is the current game level
 */
void display_game_level (uint8_t gamelevel);

/*
 * Display's the user has lost
 */
void lose_screen (void);

/*
 * Display's the user has won
 */
void win_screen (void);

#endif //WELCOME_H
