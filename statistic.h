#include <stdio.h>
#include <string.h>

int open_file_g();

int open_file_p(int player_);

int write_file(int file_);

void top_5();

void encryptor_global(struct global_stats gs_);

void encryptor_player(struct global_player ps_);

struct global_stats decryptor_global(char *buffer_);

struct global_player decryptor_player(char *buffer_);

void display_stats_global();

void display_stats_player(int player_);
