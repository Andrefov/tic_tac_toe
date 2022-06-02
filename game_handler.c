//#define _CRT_SECURE_NO_WARNINGS // with this i can use scanf, instead scanf_s
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.c"
#include "board.c""
#include "statistic.h"

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

		// dopisanie remisu i rundy do pierwszego gracza 
		gh_ps1.draw++;
		gh_ps1.rounds++;
		gh_ps1.moves = move_player1; // doliczenie ruchów

		// dopisanie remisu i rundy do drugiego gracza 
		gh_ps2.draw++;
		gh_ps2.rounds++;
		gh_ps2.moves = move_player2; // doliczenie ruchów
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
			gh_ps1.moves = move_player1; // doliczanie ruchów do wygranego

			gh_ps2.losts++;
			gh_ps2.rounds++;
			gh_ps2.moves = move_player2;
		}
		else if (gh_player_mark == 2) {
			printf("Congratulations %s, you have won!\n", gh_ps2.name);
			gh_ps2.wins++;
			gh_ps2.rounds++;
			gh_ps2.moves = move_player2; // doliczanie ruchów dla wygranego

			gh_ps1.losts++;
			gh_ps1.rounds++;
			gh_ps1.moves = move_player1;
		}
		else {
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


void round() {

	if (selected_mode == 1) {// player vs player

		do {
			start_board();

			while (is_win() == -1) {

				print_board();

				which_player = 1;
				player_one_move(take_coordinate(which_player));
				gh_ps1.move = move_player1;
				print_board();

				if (is_win() >= 0) {
					break;
				}

				print_board();

				which_player = 2;
				player_two_move((take_coordinate(which_player));
				gh_ps2.move = move_player2;
				print_board();
			}
			print_game_state();
			move_player1 = 0;
			move_player2 = 0;

		} while (one_more_game() == 1);
	}

	else if (selected_mode == 2) { // player vs comp

		start_board();

		switch (ai_level)
		{
		case 1: // poziom trudności dummy
			print_board();

			do {
				while (is_win() == -1) {

					if (player1_selected_symbol == 1)
					{
						print_board();

						which_player = 1;
						player_one_move(take_coordinate(which_player));
						gh_ps1.move = move_player1;
						print_board();

						if (is_win() >= 0) {
							break;
						}
						print_board();
						player_one_move(dummy_move());
						sleep(100);

					}
					else if (player_selected_symbol == 2)
					{
						print_board();
						player_one_move(dummy_move());
						sleep(100);

						if (is_win() >= 0) {
							break;
						}

						which_player = 1;
						player_two_move(take_coordinate(which_player));
						gh_ps1.move = move_player1;
						print_board();
					}
				}
				print_game_state();
				move_player1 = 0;
				move_player2 = 0;

			} while (one_more_game() == 1);
			break;
		}

	}

	case 2: // poziom trudności pro
		print_board();

		do {
			while (is_win() == -1) {

				if (player1_selected_symbol == 1)
				{
					print_board();

					which_player = 1;
					player_one_move(take_coordinate(which_player));
					gh_ps1.move = move_player1;
					print_board();

					if (is_win() >= 0) {
						break;
					}
					print_board();
					player_one_move(pro_move());
					sleep(100);

				}
				else if (player_selected_symbol == 2) {
					print_board();
					player_one_move(pro_move());
					sleep(100);

					if (is_win() >= 0) {
						break;
					}

					which_player = 1;
					player_two_move(take_coordinate(which_player));
					gh_ps1.move = move_player1;
					print_board();
				}
			}
			print_game_state();
			move_player1 = 0;
			move_player2 = 0;

		} while (one_more_game() == 1);
		break;

	default:
		break;
}

	else if (selected_mode == 3) {		// comp vs comp

	print_board();

	switch (ai_level) {
	case 1: //poziom trudności dummy
		print_board();

		while (is_win() == -1) {
			if (player_selected_symbol == 1)
			{
				print_board();
				player_one_move(dummy_move());
				sleep(100);
				
				if (is_win() >= 0) {
					break;
				}
				print_board();
				player_two_move(dummy_move());
				sleep(100);
			}
			print_game_state();
			move_player1 = 0;
			move_player2 = 0;
		} while (one_more_game() == 1);
		break;

	case 2: // poziom trudności pro
		print_board();

		while (is_win() == -1) {
			if (player_selected_symbol == 1)
			{
				print_board();
				player_one_move(pro_move());
				sleep(100);

				if (is_win() >= 0) {
					break;
				}
				print_board();
				player_two_move(pro_move());
				sleep(100);
			}
			print_game_state();
			move_player1 = 0;
			move_player2 = 0;
		} while (one_more_game() == 1);
		break;
	
	default:
		break;
	}

}

