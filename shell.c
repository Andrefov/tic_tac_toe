#include<stdio.h>
#include<string.h>
#include<ctype.h>

int readline(char* line, size_t len) {
	line[len - 1] = 0xaa;

	if (fgets(line, len, stdin) == NULL) {
		printf("critical error\n");
		return -1;
	}

	if (line[len - 1] == "\0" && line[len - 2] == "\n") {
		printf("critical error\n");
		return -1;
	}
	line[strlen(line) - 1] = '\0';
}

int select_mode()
{//user chooses the game mode
	int option;
	printf("Select mode:\n1.Player vs Player\n2.Player vs Computer\n3.Computer vs Computer \n>>>");
	scanf_s("%d", &option),2;

	switch (option)
	{
		case 1:
			printf("Player vs Player mode!\n");
			select_symbol();
			break;    // do testow
			//game
			return 1;
			
		case 2:
			printf("Player vs Computer mode!\n");
			Ai_level();
			select_symbol();
			//game
			return 2;
		case 3:
			printf("Computer vs Computer mode\n");
			break;   //do testow
			//game
			return 3;
		default:
			printf("Unknown option\n");
			return -1;
	}
}

int Ai_level()
{
	//user can choose the AI level
	int level;
	printf("Select AI level:\n1.Easy\n2.Hard \n>>>");


	while (1)
	{
		scanf_s("%d", &level);
		if (level == 1)
		{
			printf("Easy!\n");
			return 1;
		}
		else if (level == 2)
		{
			printf("Hard!\n");
			return 2;
		}
		else
		{
			printf("Unknown option!\nTry again>>>");
			continue;
		}
	}

}

int select_symbol()
{
	//user can choose the symbol
	int symbol;
	printf("Select your symbol:\n1.X\n2.O \n>>>");
	
	while (1)
	{
		scanf_s("%d", &symbol);
		if (symbol == 1)
		{
			printf("'X' symbol choosen.\n");
			return 1;
		}
		else if (symbol == 2)
		{
			printf("'O' symbol choosen.\n");
			return 2;
		}
		else
		{
			printf("Unknown option!\nTry again>>>");
			continue;
		}
	}

}



void end_game_results(int result)
{	//func gives game results
	if (result == 1)
	{
		printf("You win!\n");
	}
	else if (result == -1)
	{
		printf("You lose!\n");
	}
	else if (result == 0)
	{
		printf(" Draw!\n");
	}
}

int one_more_game()
{
	//func asks user if he want to play again
	char choice[6];

	printf("Do you want play again? Type 'yes', 'no' or 'quit' to return to main menu. \n>>>");
	// cos nie dziala, przenosi od razu do elsa
	while (1)
	{
		
		if (readline(choice, sizeof(choice)) == 0)
		{
			continue;
		}
		else if (strncmp(choice, "yes", 4) == 0)
		{
			printf("lets play again\n");
			return 1;
		}
		else if (strncmp(choice, "no", 4) == 0)
		{
			printf("no more game\n");
			return -1;
		}
		else if (strncmp(choice, "quit", 6) == 0)
		{
			printf("returning to main menu\n");
			return 0;
		}
		else
		{
			printf("invalid input. Try again\n>>>");

		}
	}
	
	
}

void help_menu()
{
	//func describe possibilities for user
	printf("MENU:\n");
	printf("1. Play game\n");
	printf("2. View global stats\n");
	printf("3. View player stats\n");
	printf("4. Exit\n");
	printf(">>>");

}

int take_coordinate()
{
	// func takes coordinate from user
	int cor;
	printf("Enter coordinate (1-9 field)\n>>>");

	while (1)
	{
		scanf_s("%d",&cor);
		if ((cor > 9) || (cor < 1))
		{
			printf("Invalid position! Try again>>>");
			continue;
		}
		break;
	}

	return cor;
}

int display_menu()
{	
	help_menu();
	//loop for navigate in the menu
	int choice;
	
	while (1)
	{
		scanf_s("%d", &choice);

		if ((choice < 1) || (choice > 4))
		{
			printf("Invalid input. Try again");
			continue;
		}
		
		break;
	}
	// po wpisaniu litery mam blad na stosie.

	if (choice == 1)
	{
		select_mode();
	}
	else if (choice == 2)
	{
		//display_stats_global()
	}
	else if (choice == 3)
	{
		//display_stats_player(player_)
	}
	else
	{
		//exit to main menu
	}
	return 0;
}


void get_name()
{
	// user sets a name
	char* name[10];
	printf("What is your name? max 8 characters\n>>>");
	readline(name, sizeof(name));
	printf("Hello %s, welcome in TicTacToe Game\n\n", name);
}

int main()
{
	//testowy main

	get_name();
	
	
	
	display_menu();

	int result = 1;
	end_game_results(result);

	one_more_game();

	int coordinate;

	coordinate = take_coordinate();
	
	printf("choosen coordinate is %d", coordinate);

	return 0;

}