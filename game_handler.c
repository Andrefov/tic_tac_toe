//#define _CRT_SECURE_NO_WARNINGS // with this i can use scanf, instead scanf_s
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// commented only for local tests
//#include "statistic.h" // this wil be required to be able te define the structures in the same way
// structures in statistic.c could also be defined with as 'extern'

#pragma warning(disable : 4996)


// ####################################### ONLY FOR TESTING LOCALLY!!! 
//TODO: delete or comment me me before pushing merging etc
 // /* <-- just comment/uncomment this line
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
// ####################################### END OF SECTION ONLY FOR TESTING LOCALLY!!! */
//https://stackoverflow.com/questions/38684164/case-insensitive-string-comparison-in-c
// returns 0 if strings are different
// returns 1 if strings are the same (case insensitive) 
//
int iequals(const char* a, const char* b) {
	unsigned int size1 = strlen(a);
	if (strlen(b) != size1)
		return 0;
	for (unsigned int i = 0; i < size1; i++)
		if (tolower(a[i]) != tolower(b[i]))
			return 0; 
	return 1;
}

// Game Handler #1
void printGameState(int gh_gameStatus, int gh_playerMark, char gh_PlayerOoneName[8], char gh_PlayerXtwoName[8], struct global_stats* gh_globalStats, struct player_stats* gh_playerStats) {
	int found_player = 0, iter = 0;
	// int gameStatus (infro from baord)
	//	-1 - initial and in progress
	//	0 - tie
	//	1 - somebody won
	switch (gh_gameStatus) {
	case -1:
		printf("Game in progress..\n");
		break;
	case 0:
		printf("Game over!. Nobody won.\n");
		if (strcmp(gh_PlayerOoneName, "Nobody") == 0 || strcmp(gh_PlayerXtwoName, "Nobody") == 0) // checking if player name is 'nobody' - should be case insenstive, but it's c...
		{
			printf("No, 'Nobody' does NOT mean, the cheating player called 'Nobody' has won.\n"); // just handling a very specific case where player would name himself nobody ;) 
		}
		break;
	case 1:
		printf("Game over!. We have a winner!\n");
		//char playerMark - player that have won
		//	' ' - initial
		//	'O'
		//	'X'
		if (gh_playerMark == 'O') {
			printf("Congratulations %s, you have won!\n", gh_PlayerOoneName);
			do {
				if (iequals(gh_playerStats[iter].name, gh_PlayerOoneName)) {
					gh_playerStats[iter].wins++;
				}
			} while (!found_player && iter <= sizeof(gh_playerStats));
		}
		else if (gh_playerMark == 'X') {
			printf("Congratulations %s, you have won!\n", gh_PlayerXtwoName);
			do {
				if (iequals(gh_playerStats[iter].name, gh_PlayerXtwoName)) {
					gh_playerStats[iter].wins++;
				}
			} while (!found_player && iter <= sizeof(gh_playerStats));;
		}
		else {
			printf("Gamer error, we have a winner, but don't know who that is!\n");
		}
		break;
	default:
		printf("Game error. Status unknown.\n");

}//switch close
}//function close


// Game Handler #2
void updateWinnerStats(char gh_winnerName[8], struct global_stats* gh_globalStats, struct player_stats* gh_playerStats) {

	// how to update the statistics for a player
	// 1. no function for adding new record
	// funkcja_andrzeja_dodajaca_wygrana(nazwaGraczaKtoryWygral);
	// 2. no comments on how to do it differently (a global/extern variable/structure)
	// 3. this could be done by me returning some data/structure - this would need to be agreed on and handled in main..
	//
}

// Game Handler #3
int updateGameTimes() {

}

// Game Handler #4
int updateGameTimes() {

}


// ####################################### ONLY FOR TESTING LOCALLY!!! 
//TODO: delete or comment me me before pushing merging etc
// /* <-- just comment/uncomment this line
int main()
{
	struct global_stats gs; //used the same names as in statistics.c
	struct player_stats ps[5];
	*ps[0].name = "Nobody";
	*ps[1].name = "Body0";
	*ps[2].name = "Body1";
	*ps[3].name = "Body2";
	*ps[4].name = "Body3";
	*ps[5].name = "Body4";
	gs.time = 100;
	//while (1) {

		printGameState(0, ' ', "Nobody", "Drugi", gs, ps);
		printGameState(-1, ' ', "Nobody", "Drugi", gs, ps);
		printGameState(1, ' ', "Nobody", "Drugi", gs, ps);
		printGameState(23, ' ', "Nobody", "Drugi", gs, ps);
	//}
	printf("\n\n\n\n\nMAIN:OK\nThis is just a test");
	return 0;
}
// ####################################### END OF SECTION ONLY FOR TESTING LOCALLY!!! */

