#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include <windows.h>

#pragma warning(disable : 4996)

void start_board();
void print_board();
int is_free(int coordinate);
int is_win();
void player_one_move(int position_on_board);
void player_two_move(int position_on_board);
int who_win(char player_mark, int game_status);




// global variable with board on the board
