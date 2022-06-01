//#define _CRT_SECURE_NO_WARNINGS // with this i can use scanf, instead scanf_s
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.c"

// commented only for local tests
//#include "statistic.h" // this wil be required to be able te define the structures in the same way
// structures in statistic.c could also be defined with as 'extern'

#pragma warning(disable : 4996)
int gh_game_mode;
int gh_game_status;
int gh_player_mark; //????????????----------- int or char -----------------????
int gh_game_time;
int gh_game_moves;


// ####################################### ONLY FOR TESTING LOCALLY!!! 
//TODO: delete or comment me me before pushing merging etc
 // /* <-- just comment/uncomment this line
struct global_stats {
	int time; // ??????????-------> int ????
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

struct global_stats gh_gs;
struct player_stats gh_ps1;
struct player_stats gh_ps2;


// ####################################### END OF SECTION ONLY FOR TESTING LOCALLY!!! */
void increase_time() {
	gh_ps1.time + gh_game_time; // gh_game_time - to ma dostarczyć info BOARD - do doliczania czasu
	gh_ps2.time + gh_game_time;
}

void print_game_state() 
{
	//Game Mode from Shell:  1.Player vs Player 2.Player vs Computer 3.Computer vs Computer
	// int gameStatus (infro from baord)
	//	-1 - initial and in progress
	//	0 - tie
	//	1 - somebody won
	increase_time();

	switch (gh_game_status)
	{
	case -1:
		printf("Game in progress..\n");
		break;


	case 0: // draw/tie
		printf("\nGame over!. Nobody won.\n");
		gh_gs.draw++; 
		gh_gs.rounds++;
		

		if (gh_game_mode > 1 ) // ustalić na stałe imię compa
		{
			gh_gs.comp_vs++;
			printf("global stats of comp vs were incremented\n");
		}
		 // dopisanie remisu i rundy do pierwszego gracza 
			gh_ps1.draw++;
			gh_ps1.rounds++;
			gh_ps1.moves + gh_game_moves; // doliczenie ruchów
			printf("player number %s draw and rounds were incremented.\n", gh_ps1.name);
		
		// dopisanie remisu i rundy do drugiego gracza 
			gh_ps2.draw++;
			gh_ps2.rounds++;
			gh_ps2.moves + gh_game_moves; // doliczenie ruchów
			printf("player number %s draw and rounds were incremented.\n", gh_ps2.name);
			
		break;


	case 1: // SOMEONE have won (there is a winner and looser)
		printf("\nGame over!. We have a winner!\n");
		//char playerMark - player that have won
		//	' ' - initial
		//	'O'
		//	'X'
		gh_gs.wins++;
		gh_gs.losts++;
		gh_gs.rounds++;

		if (gh_game_mode > 1)
		{
			gh_gs.comp_vs++;
			printf("global stats of comp vs were incremented\n");
		}

		if (gh_player_mark == 1) // zmienna z board który gracz wygrał
		{
			printf("Congratulations %s, you have won!\n", gh_ps1.name);
			gh_ps1.wins++;
			gh_ps1.rounds++;
			gh_ps1.moves + gh_game_moves; // doliczanie ruchów do wygranego
			
			gh_ps2.losts++;
			gh_ps2.rounds++;
			gh_ps2.moves + gh_game_moves - 1;
		} else if (gh_player_mark == 2) {
			printf("Congratulations %s, you have won!\n", gh_ps2.name);
			gh_ps2.wins++;
			gh_ps2.rounds++;
			gh_ps2.moves + gh_game_moves; // doliczanie ruchów dla wygranego

			gh_ps1.losts++;
			gh_ps1.rounds++;
			gh_ps1.moves + gh_game_moves - 1; 
		} else {
			printf("\nGamer error, we have a winner, but don't know who that is!\n");
		}
		break;

	default:
		printf("\nGame error. Status unknown.\n");

	}
}


void print_player_statistic(struct player_stats ps) {
	printf("Player statistic for %s\n", ps.name);
	printf("Time: %d", ps.time);

}


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

