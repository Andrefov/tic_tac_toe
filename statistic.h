#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)

struct global_stats {
	int time;
	int wins;
	int losts;
	int draw;
	int rounds;
	int comp_vs;
};

struct player_stats {
	char name[8];
	int time;
	int wins;
	int losts;
	int draw;
	int rounds;
	int moves;
};

struct global_stats gs;

struct player_stats ps;

int open_file_g();

int open_file_p(int player_);

int write_file(int file_);

void top_5();

void encryptor_global(struct global_stats gs_);

void encryptor_player(struct player_stats ps_);

struct global_stats decryptor_global(char *buffer_);

struct player_stats decryptor_player(char *buffer_);

void display_stats_global();

void display_stats_player(int player_);
