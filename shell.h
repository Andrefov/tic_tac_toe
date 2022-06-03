#include <stdio.h>
#include <string.h>
#include <ctype.h>



int readline(char* line, size_t len);

int select_mode();

int ai_level_select();

int select_symbol();

void end_game_results(int result);

int one_more_game();

void help_menu();

int take_coordinate(int which_player);

int display_menu();

void get_p1_name(int mode);

void get_p2_name();