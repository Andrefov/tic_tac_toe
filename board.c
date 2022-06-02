#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#pragma warning(disable : 4996)

void startBoard();
void printBoard();
int isFree(int coordinate);
int isWin();
void playerOneMove(int positionOnBoard);
void playerTwoMove(int positionOnBoard);
int whoWin(char playerMark, int gameStatus);




// global variable with board on the board
char board[9];
const char PLAYER_ONE = 'O';
const char PLAYER_TWO = 'X';
double howLong;
clock_t begin, end;

int main() {

	int gameStatus = -1;
	char playerMark = ' '; //X' or 'Y' for player



	startBoard(); // display board with index

	if (are you ready ? )    /// argument from shell if sombedoy start a game 
		begin = clock();

	while (gameStatus < 0)
	{
		printBoard();

		// PLAYER ONE
		playerOneMove();
		gameStatus = isWin();
		playerMark = 'O';
		if (gameStatus >= 0)
			break;
		printBoard();
		// PLAYER TWO
		playerTwoMove();
		gameStatus = isWin();
		playerMark = 'X';
		if (gameStatus >= 0)
			break;


	}

	printBoard();
	whoWin(playerMark, gameStatus);


	return 0;
}

void startBoard() {
	/* Function display start board with index
	INPUT:
	OUTPUT:
	*/

	for (int i = 0; i < 9; i++) {
		board[i] = 49 + i;
	}
}

void printBoard() {
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

int isFree(int coordinate) {
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

int isWin() {
	/* Function check is player win or not
	INPUT:
	OUTPUT: integer value:
			 1 - win,
			 0 - tie,
			-1 - in progress
	*/
	int gameResult = 0;

	// horizontal win
	for (int i = 0; i < 9; i += 3) {
		if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
			return gameResult = 1;
	}

	//vertical win
	for (int i = 0; i < 3; i++) {
		if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
			return gameResult = 1;
	}

	//cross win

	if (board[0] == board[4] && board[4] == board[8])
		return gameResult = 1;
	else if (board[2] == board[4] && board[4] == board[6])
		return gameResult = 1;

	// tie - no more free spaces

	else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
		board[3] != '4' && board[4] != '5' && board[5] != '6' &&
		board[6] != '7' && board[7] != '8' && board[8] != '9')
		return gameResult = 0;

	// game is in progress
	else
		return gameResult = -1;

}

void playerOneMove(int positionOnBoard) {
	/* Function display move PLAYER_TWO ont the board
	INPUT: integer - posiiton on the board
	OUTPUT:
	*/
	int playerInput = positionOnBoard;

	do {
		printf("PLAYER 1, please give a position: \n");
		playerInput--;
		if (isFree(playerInput))
		{
			board[playerInput] = PLAYER_ONE;
			break;
		}
		else
			printf("Position is unevailable ");
	} while (!isFree(playerInput));
	system("cls");
}

void playerTwoMove(int positionOnBoard) {
	/* Function display move PLAYER_TWO ont the board
	INPUT: integer - posiiton on the board
	OUTPUT:
	*/

	int playerInput = positionOnBoard;

	do {
		printf("PLAYER 2, please give a position: \n");
		playerInput--;

		if (isFree(playerInput))
		{
			board[playerInput] = PLAYER_TWO;
			break;
		}
		else
			printf("Position is unevailable ");
	} while (!isFree(playerInput));
	system("cls");
}

int whoWin(char playerMark, int gameStatus) {
	/* Function display who is the winner or is a tie
	INPUT:
	OUTPUT: integer descrpie who win  player one =1 or player two = 2 or tie =0
	*/
	if (gameStatus == 0)
	{
		end = clock();
		howLong = end - begin;
		printf("IT'S A TIE!\n");
		return 0;
	}
	else if (playerMark == PLAYER_ONE) {
		end = clock();
		howLong = end - begin;
		printf("PLAYER ONE WIN!\n");
		return 1;
	}
	else if (playerMark == PLAYER_TWO)
	{
		end = clock();
		howLong = end - begin;
		printf("PLAYER TWO WIN!\n");
		return 2;
	}

}
