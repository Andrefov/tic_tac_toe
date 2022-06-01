#include<stdio.h>
#include<string.h>
#include<ctype.h>

int selected_mode=0, player1_selected_symbol = 0, player2_selected_symbol = 0, one_more = 0, AI_level = 0;     //selected mode: int 1 or 2 or 3
char* player1_name[8], player2_name[8];

int readline(char* line, size_t len);

const char* get_name();

int select_mode();

int Ai_level();

int select_symbol();

void end_game_results(int result);

int one_more_game();

void help_menu();

int take_coordinate();

int display_menu();

void choose_my_name(char* imie)
{
	fgets(imie, 30, stdin);
}

int main()
{

	display_menu();

	printf("wybrany symbol to %d\n", player1_selected_symbol);
	printf("wybrany mode to %d\n", selected_mode);
	printf("player1 name is %s", player1_name);


	//char* player1name = get_name();
	//printf("%s", player1name);
	//settings:
	
	return 0;
}

int display_menu()
{
	help_menu();
	//loop for navigate in the menu
	int choice;
	char* line[1];

	while (1)
	{
		readline(line, sizeof(line));
		choice = atoi(line);

		if ((choice < 1) || (choice > 4))
		{
			printf("Invalid input. Try again>>>");
			continue;
		}
		else if (choice == 1)
		{
			selected_mode = select_mode();
			break;

		}
		else if (choice == 2)
		{
			//display_stats_global()
		}
		else if (choice == 3)
		{
			//display_stats_player(player_)
		}
		else if (choice == 4)
		{
			//exit 
			break;
		}
	}
	return 0;
}

int readline(char* line, size_t len)
{
	//functions takes input from user
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

const char* get_name()
{
	// user sets a name
	char* name[8];
	readline(name, sizeof(name));

	return name;
}

int select_mode()
{//user chooses the game mode
	int option = 0;
	char* line[1];

	printf("Select mode:\n1.Player vs Player\n2.Player vs Computer\n3.Computer vs Computer \n>>>");

	while (1)
	{
		readline(line, sizeof(line));
		option = atoi(line);

		if (option == 1)
		{
			printf("Player vs Player mode!\n");

			printf("Enter the first player's name\n>>>");
			choose_my_name(player1_name);

			player1_selected_symbol = select_symbol();

			printf("Enter the second player's name\n>>>");
			choose_my_name(player2_name);
			player2_selected_symbol = select_symbol();

			return 1;
		}
		else if (option == 2)
		{
			printf("Player vs Computer mode!\n");
			printf("Enter the first player's name\n>>>");
			choose_my_name(player1_name);
			player1_selected_symbol = select_symbol();
			AI_level = Ai_level();
			return 2;
		}
		else if (option == 3)
		{
			printf("Computer vs Computer mode\n");
			return 3;
		}
		else
		{
			printf("Unknown option\nTry again>>>");
			continue;
		}
	}

}

int Ai_level()
{
	//user can choose the AI level
	int level = 0;
	char* line[1];
	printf("Select AI level:\n1.Easy\n2.Hard \n>>>");

	while (1)
	{
		readline(line, sizeof(line));
		level = atoi(line);

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
	int symbol = 0;
	char* line[1];

	printf("Select your symbol:\n1.X\n2.O \n>>>");

	while (1)
	{
		readline(line, sizeof(line));
		symbol = atoi(line);

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
		printf("It's a tie!\n");
	}
}

int one_more_game()
{
	//func asks user if he want to play again
	char choice[6];

	printf("Do you want play again? Type 'yes', 'no' or 'quit' to return to main menu. \n>>>");

	while (1)
	{
		readline(choice, sizeof(choice));

		if (strncmp(choice, "yes", 4) == 0)
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
	char* line[1];
	printf("Enter coordinate (1-9 fields)\n>>>");

	while (1)
	{
		readline(line, sizeof(line));
		cor = atoi(line);

		if ((cor <= 9) && (cor >= 1))
		{
			break;
		}
		else
		{
			printf("Invalid input. Try again>>>");
			continue;
		}
	}
	return cor;
}