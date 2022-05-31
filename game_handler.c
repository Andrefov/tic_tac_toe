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



// Game Handler #1
void printGameState(int gh_gameMode, int gh_gameStatus, int gh_playerMark, char gh_PlayerOoneName[8], char gh_PlayerXtwoName[8], struct global_stats gh_globalStats, struct player_stats* gh_playerStats) {
	int found_player = 0, iter = 0;
	//Game Mode from Shell:  1.Player vs Player 2.Player vs Computer 3.Computer vs Computer
	// int gameStatus (infro from baord)
	//	-1 - initial and in progress
	//	0 - tie
	//	1 - somebody won
	switch (gh_gameStatus)
	{
	case -1:
		printf("Game in progress..\n");
		break;


	case 0: // draw/tie
		printf("\nGame over!. Nobody won.\n");
		gh_globalStats.draw++; 
		gh_globalStats.rounds++;

		if (gh_gameMode > 1)
		{
			gh_globalStats.comp_vs++;
			printf("global stats of comp vs were incremented\n");
		}

		if (strcmp(gh_PlayerOoneName, "Nobody") == 0 || strcmp(gh_PlayerXtwoName, "Nobody") == 0) // checking if player name is 'nobody' - should be case insenstive, but it's c...
		{
			printf("No, 'Nobody' does NOT mean, the cheating player called 'Nobody' has won.\n"); // just handling a very specific case where player would name himself nobody ;) 
		}


		do
		{
			if (strcmp(gh_playerStats[iter].name, gh_PlayerOoneName))
			{
				gh_playerStats[iter].draw++;
				gh_playerStats[iter].rounds++;
				printf("player number %d draw and rounds were incremented.\n", iter);
				found_player = 1;
			}
			iter++;
		} while (!found_player && iter <= sizeof(gh_playerStats));


		do
		{
			if (strcmp(gh_playerStats[iter].name, gh_PlayerXtwoName)) {
				gh_playerStats[iter].draw++;
				gh_playerStats[iter].rounds++;
				printf("player number %d draw and rounds were incremented.\n", iter);
				found_player = 1;
			}
			iter++;
		} while (!found_player && iter <= sizeof(gh_playerStats));
		break;


	case 1: // SOMEONE have won (there is a winner and looser)
		printf("\nGame over!. We have a winner!\n");
		//char playerMark - player that have won
		//	' ' - initial
		//	'O'
		//	'X'
		gh_globalStats.wins++;
		gh_globalStats.losts++;
		gh_globalStats.rounds++;

		if (gh_gameMode > 1)
		{
			gh_globalStats.comp_vs++;
			printf("global stats of comp vs were incremented\n");
		}
		if (gh_playerMark == 'O')
		{
			printf("Congratulations %s, you have won!\n", gh_PlayerOoneName);
			do
			{
				if (strcmp(gh_playerStats[iter].name, gh_PlayerOoneName)) 
				{
					gh_playerStats[iter].wins++;
					gh_playerStats[iter].rounds++;
					printf("player number %d win and rounds were incremented.\n", iter);
					found_player = 1;
				}
				iter++;
			} while (!found_player && iter <= sizeof(gh_playerStats));


			do
			{
				if (strcmp(gh_playerStats[iter].name, gh_PlayerXtwoName))
				{
					gh_playerStats[iter].losts++;
					gh_playerStats[iter].rounds++;
					printf("player number %d lost and rounds were incremented.\n", iter);
					found_player = 1;
				}
				iter++;
			} while (!found_player && iter <= sizeof(gh_playerStats));
		}

		else if (gh_playerMark == 'X') 
		{
			printf("Congratulations %s, you have won!\n", gh_PlayerXtwoName);

			do 
			{
				if (strcmp(gh_playerStats[iter].name, gh_PlayerXtwoName)) 
				{
					gh_playerStats[iter].wins++;
					gh_playerStats[iter].rounds++;
					printf("player number %d win and rounds were incremented.\n", iter);
					found_player = 1;
				}
				iter++;
			} while (!found_player && iter <= sizeof(gh_playerStats));


			do 
			{
				if (strcmp(gh_playerStats[iter].name, gh_PlayerOoneName))
				{
					gh_playerStats[iter].losts++;
					gh_playerStats[iter].rounds++;
					printf("player number %d win and rounds were incremented.\n", iter);
					found_player = 1;
				}
				iter++;
			} while (!found_player && iter <= sizeof(gh_playerStats));
		}

		else {
			printf("\nGamer error, we have a winner, but don't know who that is!\n");
		}
		break;

	default:
		printf("\nGame error. Status unknown.\n");

	}//switch close
}//function close


// ####################################### ONLY FOR TESTING LOCALLY!!! 
//TODO: delete or comment me me before pushing merging etc
// /* <-- just comment/uncomment this line
int main()
{
	struct global_stats gs; //used the same names as in statistics.c
	struct player_stats ps[5] = {
		{.name = "Nobody"},
		{.name = "Body0"},
		{.name = "Srody"},
		{.name = "Czwartki"},
		{.name = "Dupa"}
	};
	gs.time = 100;
	//while (1) {
		printf("###\nTEST: tie, compvs, nobody and body0\n");
		printGameState(2, 0, ' ', "Nobody", "Body0", gs, ps);

		printf("###\nTEST: in progress compvs, nobody and body0\n");
		printGameState(2, -1, ' ', "Nobody", "Body0", gs, ps); //in progress/initial

		printf("###\nTEST: winner/looser compvs, nobody and body0\n");
		printGameState(2, 1, ' ', "Nobody", "Body0", gs, ps); //winner/looser but we don't know who

		printf("###\nTEST: winner/looser, player 2 compvs, nobody and body0\n");
		printGameState(2, 1, 'X', "Nobody", "Body0", gs, ps); //winner/looser and it is player 2

		printf("###\nTEST: error compvs, nobody and body0\n");
		printGameState(2, 5, ' ', "Nobody", "Body0", gs, ps); //error!
	//}
	printf("\n\n\n\n\nMAIN:OK\nThis is just a test");
	return 0;
}
// ####################################### END OF SECTION ONLY FOR TESTING LOCALLY!!! */

