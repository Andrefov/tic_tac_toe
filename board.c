#include "board.h"
#include "shell.h"

#pragma warning(disable : 4996)

const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'O';
extern int which_player;
char board[9];

double how_long;
int move_player1, move_player2;  // counter for player moves: player1 and player 2
clock_t begin, end;

// global variable with board on the board


void start_board() {
	/* Function display start board with index
	INPUT:
	OUTPUT:
	*/

	for (int i = 0; i < 9; i++) {
		board[i] = 49 + i;
	}
}

void print_board() {
	/* Function display plane
	INPUT:
	OUTPUT:
	*/

	system("cls");
	printf("\n\n\ TiC TaC ToE GaME\n\n");
	printf("\t   |   |   \n");
	printf("\t %c | %c | %c \n", board[0], board[1], board[2]);
	printf("\t___|___|___\n");

	printf("\t   |   |   \n");
	printf("\t %c | %c | %c \n", board[3], board[4], board[5]);
	printf("\t___|___|___\n");

	printf("\t   |   |   \n");
	printf("\t %c | %c | %c \n", board[6], board[7], board[8]);
	printf("\t   |   |   \n");
}

int is_free(int coordinate) {
	/* Function check if field on board is free
	INPUT: position on the board
	OUTPUT: integer
		1 - is free
		0 - is occupied
	*/
	if (board[coordinate]  == 'X' || board[coordinate] == 'O') //49 -57 -ASCI number from'1' to '9'
		return 0;
	else
		return 1;

}

int is_win() {
	/* Function check is player win or not
	INPUT:
	OUTPUT: integer value:
			 1 - win,
			 0 - tie,
			-1 - in progress
	*/
	int game_result = 0;

	// horizontal win
	for (int i = 0; i < 9; i += 3) {
		if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
			return game_result = 1;
	}

	//vertical win
	for (int i = 0; i < 3; i++) {
		if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
			return game_result = 1;
	}

	//cross win

	if (board[0] == board[4] && board[4] == board[8])
		return game_result = 1;
	else if (board[2] == board[4] && board[4] == board[6])
		return game_result = 1;

	// tie - no more free spaces

	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
		board[3] != '4' && board[4] != '5' && board[5] != '6' &&
		board[6] != '7' && board[7] != '8' && board[8] != '9')
		return game_result = 0;

	// game is in progress
	else
		return game_result = -1;

}

void player_one_move(int position_on_board) {
	/* Function display move PLAYER_TWO ont the board
	INPUT: integer - posiiton on the board
	OUTPUT:
	*/
	int player_input = position_on_board;
	int correct_possition = 0;

	while (correct_possition != 1) {
		
		player_input--;
		if (is_free(player_input) == 1)
		{
			board[player_input] = PLAYER_ONE;
			move_player1++; // succesful move, increment variable
			break;
		}
		else {
			printf("Position is unevailable !!!");
			Sleep(1000);
			system("cls");
			print_board();
			player_input = take_coordinate(which_player);
		}
	} 
	system("cls");
}

void player_two_move(int position_on_board) {
	/* Function display move PLAYER_TWO ont the board
	INPUT: integer - posiiton on the board
	OUTPUT:
	*/

	int player_input = position_on_board;
	int correct_possition = 0;

	while(correct_possition != 1){
		player_input--;

		if (is_free(player_input) == 1)
		{
			board[player_input] = PLAYER_TWO;
			move_player2++; // succesful move, increment variable
			break;
		}
		else
		{
			printf("Position is unevailable !!!");
			Sleep(1000);
			system("cls");
			print_board();
			player_input = take_coordinate(which_player);
		}
	} 
	system("cls");
}

int who_win(char player_mark, int game_status) {
	/* Function display who is the winner or is a tie
	INPUT:
	OUTPUT: integer descrpie who win  player one =1 or player two = 2 or tie =0
	*/
	if (game_status == 0)
	{
		end = clock();
		how_long = end - begin;
		printf("IT'S A TIE!\n");
		return 0;
	}
	else if (player_mark == PLAYER_ONE) {
		end = clock();
		how_long = end - begin;
		printf("PLAYER ONE WIN!\n");
		return 1;
	}
	else if (player_mark == PLAYER_TWO)
	{
		end = clock();
		how_long = end - begin;
		printf("PLAYER TWO WIN!\n");
		return 2;
	}

}