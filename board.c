#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#pragma warning(disable : 4996)

void start_board();
void print_board();
int is_free(int coordinate);
int is_win();
void player_one_move(int positionOnBoard);
void player_two_move(int positionOnBoard);
int who_win(char player_mark, int game_status);




// global variable with board on the board
char board[9];
const char PLAYER_ONE = 'O';
const char PLAYER_TWO = 'X';
double how_long;
int move_player1, move_player2;  // counter for player moves: player1 and player 2
clock_t begin, end;

int main() {

	int game_status = -1;
	char player_mark = ' '; //X' or 'Y' for player
	move_player1 = 0;
	move_player2 = 0;



	do {
		start_board(); // display board with index


		while (game_status < 0)
		{
			print_board();

			// PLAYER ONE
			player_one_move();
			game_status = is_win();
			player_mark = 'O';
			if (game_status >= 0)
				break;
			print_board();
			// PLAYER TWO
			player_two_move();
			game_status = is_win();
			player_mark = 'X';
			if (game_status >= 0)
				break;


		}

		print_board();
		who_win(player_mark, game_status);
	} while (one more game())   // 0- no more game, 1 - play another round

	return 0;
}

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

	//printf("\n\n\ TiC TaC ToE GaME\n\n");
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
	if (board[coordinate] < 49 || board[coordinate] > 57) //49 -57 -ASCI number from'1' to '9'
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

void player_one_move(int positionOnBoard) {
	/* Function display move PLAYER_TWO ont the board
	INPUT: integer - posiiton on the board
	OUTPUT:
	*/
	int player_input = positionOnBoard;

	do {
		printf("PLAYER 1, please give a position: \n");
		player_input--;
		if (is_free(player_input))
		{
			board[player_input] = PLAYER_ONE;
			move_player2++; // succesful move, increment variable
			break;
		}
		else
			printf("Position is unevailable ");
	} while (!is_free(player_input));
	system("cls");
}

void player_two_move(int positionOnBoard) {
	/* Function display move PLAYER_TWO ont the board
	INPUT: integer - posiiton on the board
	OUTPUT:
	*/

	int player_input = positionOnBoard;

	do {
		printf("PLAYER 2, please give a position: \n");
		player_input--;

		if (is_free(player_input))
		{
			board[player_input] = PLAYER_TWO;
			move_player2++; // succesful move, increment variable
			break;
		}
		else
			printf("Position is unevailable ");
	} while (!is_free(player_input));
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
