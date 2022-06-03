
#include "game_handler.h"


int gh_game_mode;
int gh_game_status;
int gh_player_mark; //????????????----------- int or char -----------------????
int gh_game_time;
int gh_game_moves;

extern int which_player;
extern int selected_mode;
extern int player1_selected_symbol;
extern int ai_level;
extern int one_more;
extern int move_player1, move_player2;
extern char player1_name[9], player2_name[9];


struct global_stats gh_gs;
struct player_stats gh_ps1;
struct player_stats gh_ps2;

void increase_time() {
	gh_ps1.time + gh_game_time; // gh_game_time - to ma dostarczyæ info BOARD - do doliczania czasu
	gh_ps2.time + gh_game_time;

	


}
void print_game_state()
{
	increase_time();
	switch (gh_game_status)
	{
	case -1: 	//	-1 - initial and in progress
		printf("Game in progress..\n");
		break;
	case 0: // draw/tie
		printf("\nGame over!. Nobody won.\n");
		gh_gs.draw++;
		gh_gs.rounds++;

		gs.draw += gh_gs.draw;
		gs.rounds += gh_gs.rounds;
		// dopisanie remisu i rundy do pierwszego gracza 
		ps.draw += gh_ps1.draw++;
		ps.rounds += gh_ps1.rounds++;
		ps.moves += gh_ps1.moves = move_player1;
		
		
		// doliczenie ruchów
		// dopisanie remisu i rundy do drugiego gracza 
		gh_ps2.draw++;
		gh_ps2.rounds++;
		gh_ps2.moves = move_player2; // doliczenie ruchów
		break;
	case 1: // SOMEONE have won (there is a winner and looser)
		printf("\nGame over!. We have a winner!\n");
		gs.wins +=gh_gs.wins++;
		gs.losts +=gh_gs.losts++;
		gs.rounds += gh_gs.rounds++;
		if (gh_game_mode > 1)
		{
			gh_gs.comp_vs++;
			printf("global stats of comp vs were incremented\n");
		}
		if (gh_player_mark == 1) // zmienna z board który gracz wygra³
		{
			printf("Congratulations %s, you have won!\n", gh_ps1.name);
			ps.wins += gh_ps1.wins++;
			ps.rounds += gh_ps1.rounds++;
			ps.moves += gh_ps1.moves = move_player1; // doliczanie ruchów do wygranego
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
	case 3:
		printf("You have lost, sorry. Try again !!!\n");
		if (gh_player_mark == 1) {
			gh_ps1.losts++;
			gh_ps1.moves = move_player1;
			gh_ps1.rounds++;
		}
		else if (gh_player_mark == 2) {
			gh_ps2.losts++;
			gh_ps2.moves = move_player2;
			gh_ps2.rounds++;
		}
		 // you've lost

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
		strcpy(gh_ps1.name, player1_name);
		strcpy(gh_ps2.name, player2_name);
		do {
			start_board();
			while (is_win() == -1) {
				print_board();
				which_player = 1;
				player_one_move(take_coordinate(which_player));
				gh_ps1.moves = move_player1;
				print_board();
				if (is_win() >= 0) {
					gh_game_status = is_win();
					gh_player_mark = 1;
					break;
				}
				print_board();
				which_player = 2;
				player_two_move(take_coordinate(which_player));
				gh_ps2.moves = move_player2;
				print_board();
				if (is_win() >= 0) {
					gh_game_status = is_win();
					gh_player_mark = 2;
					break;
				}
			}
			print_game_state();
			move_player1 = 0;
			move_player2 = 0;
		} while (one_more_game() == 1);
	}
	else if (selected_mode == 2) { // player vs comp
		if (ai_level == 1){// poziom trudnoœci dummy
			strcpy(gh_ps1.name, player1_name);
			do {
				start_board();
				while (is_win() == -1) {
					if (player1_selected_symbol == 1) {
						print_board();
						which_player = 1;
						player_one_move(take_coordinate(which_player));
						gh_ps1.moves = move_player1;
						print_board();
						if (is_win() >= 0) {
							gh_game_status = is_win();
							gh_player_mark = 1;
							break;
						}
						print_board();
						player_two_move(dummy_move());
						Sleep(100);
						if (is_win() >= 0) {
							gh_game_status = 3;
							break;
						}
					}
					else if (player1_selected_symbol == 2) {
						print_board();
						player_one_move(dummy_move());
						Sleep(100);
						if (is_win() >= 0) {
							gh_game_status = 3;
							break;
						}
						which_player = 1;
						print_board();
						player_two_move(take_coordinate(which_player));
						gh_ps1.moves = move_player1;
						if (is_win() >= 0) {
							gh_game_status = is_win();
							gh_player_mark = 2;
							break;
						}
						print_board();
					}
				}
				print_game_state();
				move_player1 = 0;
				move_player2 = 0;
			} while (one_more_game() == 1);
		}
		else if (ai_level == 2){
			strcpy(gh_ps1.name, player1_name);
			do {
				start_board();
				while (is_win() == -1) {
					if (player1_selected_symbol == 1) {
						print_board();
						which_player = 1;
						player_one_move(take_coordinate(which_player));
						gh_ps1.moves = move_player1;
						print_board();
						if (is_win() >= 0) {
							gh_game_status = is_win();
							gh_player_mark = 1;
							break;
						}
						print_board();
						player_two_move(pro_move());
						Sleep(100);
						if (is_win() >= 0) {
							gh_game_status = 3;
							break;
						}
						print_board();
					}
					else if (player1_selected_symbol == 2) {
						print_board();
						player_one_move(pro_move());
						Sleep(100);
						if (is_win() >= 0) {
							gh_game_status = 3;
							break;
						}
						print_board();
						which_player = 1;
						player_two_move(take_coordinate(which_player));
						gh_ps1.moves = move_player1;
						print_board();
						if (is_win() >= 0) {
							gh_game_status = is_win();
							gh_player_mark = 2;
							break;
						}
					}
				}
				print_game_state();
				move_player1 = 0;
				move_player2 = 0;
			} while (one_more_game() == 1);
		}
	}
	else if (selected_mode == 3) {		// comp vs comp
		print_board();
		if (ai_level == 1) {

			print_board();
			while (is_win() == -1) {
				if (player1_selected_symbol == 1)
				{
					print_board();
					player_one_move(dummy_move());
					Sleep(100);
					if (is_win() >= 0) {
						gh_game_status = is_win();
						break;
					}
					print_board();
					player_two_move(dummy_move());
					Sleep(100);
				}
				print_game_state();
				move_player1 = 0;
				move_player2 = 0;
			} while (one_more_game() == 1);

			if (ai_level == 2) // poziom trudnoœci pro
				print_board();
			while (is_win() == -1) {
				if (player1_selected_symbol == 1)
				{
					print_board();
					player_one_move(pro_move());
					Sleep(100);
					if (is_win() >= 0) {
						break;
					}
					print_board();
					player_two_move(pro_move());
					Sleep(100);
				}
				print_game_state();
				move_player1 = 0;
				move_player2 = 0;
			} while (one_more_game() == 1);
		}				
	}
}