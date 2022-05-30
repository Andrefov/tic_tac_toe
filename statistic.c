#include "statistic.h"

struct global_stats {
	unsigned int time;
	unsigned int wins;
	unsigned int losts;
	unsigned int rounds;
	unsigned int comp_vs;
};

struct global_stats gs;

struct player_stats {
	char name[8];
	unsigned int time;
	unsigned int wins;
	unsigned int losts;
	unsigned int rounds;
	unsigned int moves;
};

struct player_stats ps;

/* 
Total time played:
Total wins:
Total lost:
Played rounds:
Computer vs comupter rounds:
*/


/*
Player name:		max 8 char.
Total time played:
Wins:
Losts:
Played rounds:
Moves:
*/

char* stats_buffer[100];


int open_file_g() {
	FILE* stats = "0";

	stats = fopen("statsg", "r");
	if (stats == NULL){
		return -1;
	}
	else {
		while (!feof(stats)) {
			if (fgets(stats_buffer, 100, stats) == NULL) break;
			
		}
		fclose(stats);
	}
}

int open_file_p(int player_) {
	FILE* stats = "0";
	char* player = "0";
	if (player_ == 1)
		player = "statsp1";
	else if (player_ == 2)
		player = "statsp2";
	else if (player_ == 3)
		player = "statsp3";
	else if (player_ == 4)
		player = "statsp4";
	else if (player_ == 5)
		player = "statsp5";

	stats = fopen(player, "r");
	if (stats == NULL) {
		return -1;
	}
	else {
		while (!feof(stats)) {
			if (fgets(stats_buffer, 100, stats) == NULL) break;

		}
		fclose(stats);
	}
}

int write_file(int file_) {
	FILE* stats;
	char* file_s;
	if (file_ == 0)
		file_s = "statsg";
	else if (file_ == 1)
		file_s = "statsp1";
	else if (file_ == 2)
		file_s = "statsp2";
	else if (file_ == 3)
		file_s = "statsp3";
	else if (file_ == 4)
		file_s = "statsp4";
	else if (file_ == 5)
		file_s = "statsp5";

	stats = fopen(stats_buffer, "r");
	if (stats == NULL) {
		return -1;
		printf(stats);
	
	fclose(stats);
	}
}

void encryptor_global(struct global_stats gs) {
	char* temp;
	temp = gs.time;
	*stats_buffer = temp;
	strcat(stats_buffer, "\n");
	temp = gs.wins;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, "\n");
	temp = gs.losts;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, "\n");
	temp = gs.rounds;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, "\n");
	temp = gs.comp_vs;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, "\n");

	int llen = strlen(stats_buffer);
	for (int i = 0; i < llen; i++) {
		int temp_c = stats_buffer[i];
		if (temp_c / 2 == 0) {
			temp_c += 20;
			stats_buffer[i] == temp_c;
		}
		else
		{
			temp_c += 30;
			stats_buffer[i] == temp_c;
		}
	}
}

void encryptor_player(struct global_player ps_){

	char* temp;
	temp = ps.time;
	*stats_buffer = temp;
	strcat(stats_buffer, '\n');
	temp = ps.wins;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, '\n');
	temp = ps.losts;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, '\n');
	temp = ps.rounds;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, '\n');
	temp = ps.moves;
	strcat(stats_buffer, temp);
	strcat(stats_buffer, '\n');

	int llen = strlen(stats_buffer);
	for (int i = 0; i < llen; i++) {
		int temp_c = stats_buffer[i];
		if (temp_c / 2 == 0) {
			temp_c += 20;
			stats_buffer[i] == temp_c;
		}
		else
		{
			temp_c += 30;
			stats_buffer[i] == temp_c;
		}
	}
}

struct global_stats decryptor_global(char *stats_buffer_) {

	int temp_c;
	int llen = strlen(stats_buffer);
	for (int i = 0; i < llen; i++) {
		temp_c = stats_buffer[i];
		if (temp_c /2 == 0){
			stats_buffer[i] -= 20;
		}
		else
		{
			stats_buffer[i] -= 30;
		}
	}
	int jump = 0;
	char *sample;

	for (int j = 0; j < 5; j++) {
		sample = strchr(stats_buffer, '\n');
		jump = (strlen(sample)) + 1;
		*stats_buffer += jump;
		switch (j) {
		case 0:
			gs.time = atoi(sample);
		case 1:
			gs.wins = atoi(sample);
		case 2:
			gs.losts = atoi(sample);
		case 3:
			gs.rounds = atoi(sample);
		case 4:
			gs.comp_vs = atoi(sample);
		}
	}
}

