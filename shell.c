#include<stdio.h>
#include<string.h>
#include<ctype.h>


int select_mode()
{
	int option;
	printf("Select mode:\n1.Player vs Player\n2.Player vs Computer\n3.Computer vs Computer \n>>>");
	scanf_s("%d", &option);

	switch (option)
	{
		case 1:
			printf("Player vs Player mode\n!");
			return 1;
		case 2:
			printf("Player vs Computer mode!\n");
			return 2;
		case 3:
			printf("Computer vs Computer mode\n");
			return 3;
		default:
			printf("Unknown option\n");
			return -1;
	}
}

int Ai_level()
{
	int option;
	printf("Select AI level:\n1.Easy\n2.Hard");
	scanf_s("%d", &option);

	switch (option)
	{
	case 1:
		printf("Easy!\n");
		return 1;
	case 2:
		printf("Hard!\n");
		return 2;
	default:
		printf("Unknown option!\n");
		return -1;
	}
}

int select_symbol()
{

}


int main()
{
	int x;

	x = select_mode();

	printf("%d. mode has been choosen!", x);

	return 0;

}