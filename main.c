
#include "game_handler.h"
extern int one_more;
extern int selected_mode;


int main() {
	srand(time(NULL));
	for (;;) {
		if (display_menu() == 4) {
			break;
				
		}
		else if (one_more == 0) {
			system("cls");
			printf("\n\n\ TiC TaC ToE GaME\n\n");
			printf("THANK YOU FOR PLAYING !!!\n");
			printf("SEE YOU NEXT TIME !!!\n");
			Sleep(200);
			break;
		}
		else if (selected_mode >= 1 && selected_mode <= 3) {

			round();
		}
	}
	

}
