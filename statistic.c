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
	FILE* stats;

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
	FILE* stats;
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
	return 0;
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

	stats = fopen(stats_buffer, "w");
	if (stats == NULL) {
		return -1;
		fwrite(stats_buffer, 1,sizeof(stats_buffer), stats);
	
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

void encryptor_player(struct player_stats ps_){

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

struct player_stats decryptor_player(char* stats_buffer_) {

	int temp_c;
	int llen = strlen(stats_buffer);
	for (int i = 0; i < llen; i++) {
		temp_c = stats_buffer[i];
		if (temp_c / 2 == 0) {
			stats_buffer[i] -= 20;
		}
		else
		{
			stats_buffer[i] -= 30;
		}
	}
	int jump = 0;
	char* sample;

	for (int j = 0; j < 6; j++) {
		sample = strchr(stats_buffer, '\n');
		jump = (strlen(sample)) + 1;
		*stats_buffer += jump;
		switch (j) {
		case 0:
			*ps.name = sample;
		case 1:
			ps.wins = atoi(sample);
		case 2:
			ps.wins = atoi(sample);
		case 3:
			ps.losts = atoi(sample);
		case 4:
			ps.rounds = atoi(sample);
		case 5:
			ps.moves = atoi(sample);
		}
	}
}

void display_stats_global() {
	if (open_file_g() == -1) {
		printf("======= GLOBAL STATISTICS =======\n\n");
		printf("Nothing to see here yet, try later\n");
	}
	else {
		decryptor_global(stats_buffer);

		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		if (gs.time >= 3600) {
			hours = gs.time / 3600;
			minutes = (gs.time - (hours * 3600)) / 60;
			seconds = gs.time - (hours * 3600) - (minutes * 60);
		}
		else if (gs.time < 3600) {
			minutes = gs.time / 60;
			seconds = gs.time - (minutes * 60);
		}
		else
			seconds = gs.time;

		printf("======= GLOBAL STATISTICS =======\n\n");
		printf("Total time played: %d h, %d m, %d s.\n", hours, minutes, seconds);
		printf("Total wins: %d.\n", gs.wins);
		printf("Total Losts: %d.\n", gs.losts);
		printf("Rounds: %d.\n", gs.rounds);
		printf("Computer vs Computer: %d.\n\n", gs.comp_vs);
	}
}

void display_stats_player(int player_) {
	open_file_p(player_);
	decryptor_player(stats_buffer);



	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	if (gs.time >= 3600) {
		hours = gs.time / 3600;
		minutes = (gs.time - (hours * 3600)) / 60;
		seconds = gs.time - (hours * 3600) - (minutes * 60);
	}
	else if (gs.time < 3600) {
		minutes = gs.time / 60;
		seconds = gs.time - (minutes * 60);
	}
	else
		seconds = gs.time;
	printf("======= Player %s =======\n\n", ps.name);
	printf("Total time played: %d h, %d m, %d s.\n", hours, minutes, seconds);
	printf("Total wins: %d.\n", ps.wins);
	printf("Total Losts: %d.\n", ps.losts);
	printf("Rounds: %d.\n", ps.rounds);
	printf("Computer vs Computer: %d.\n\n", ps.moves);

}

void top_5() {
	int i = 0;
	int players_found = 0;
	int wins[5];
	int player_index[5] = { 1,2,3,8,5 };
	int swap;
	char player_t[5][8];
	memset(player_t, ' ', 32);
	
	while ( i < 5) {
		if (open_file_p(i) == 0) {
			players_found++;
			decryptor_player(stats_buffer);
			wins[i] = ps.wins;
			*player_t[i] = ps.name;
		}
		else
			i = 5;
	}
	if (players_found >= 2) {
		for (int i = 0; i < (players_found - 1); i++) {
			for (int j = 0; j < (players_found - 1); j++) {
				if (wins[j] < wins[j + 1]) {
					swap = wins[j];
					wins[j] = wins[j + 1];
					wins[j + 1] = swap;

					swap = player_index[j];
					player_index[j] = player_index[j + 1];
					player_index[j + 1] = swap;

				}
			}
		}
	}

	printf(" === Name: ==== Wins: =======\n");
	for (int k = 0; k < players_found; k++) {
		printf("  %-8s     %-4d\n", player_t[k], wins[k]);
	}
}