#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "statistic.h"
#include "board.h"
#include "ailogic.h"

// commented only for local tests
//#include "statistic.h" // this wil be required to be able te define the structures in the same way
// structures in statistic.c could also be defined with as 'extern'


void increase_time();
void print_game_state();
void round();
void print_player_statistic(struct player_stats ps);
