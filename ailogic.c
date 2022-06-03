#include "ailogic.h"
extern char board[9];





int size;


int dummy_move() {
	int occupied_number = 0;
	int free_to_go_number = 0;

	for (int i = 0; i < 9; i++) {
		if (is_free(i) == 0) {

			occupied_number++;
		}
		else {
			free_to_go_number++;
		}
	}
	while (is_free(size) == 0) {
		size = rand() % 9;
	}
	size++;
	return size;

}

int pro_move() {
	int occupied_number = 0;
	int free_to_go_number = 0;
		
	for (int i = 0; i < 9; i++) {
		if (is_free(i) == 0) {
			occupied_number++;
		}
		else {
			free_to_go_number++;
		}
	}
	if (free_to_go_number == 9) {
		while (size != 0 || size != 2 || size != 6 || size != 8) {
			if (is_free(size) == 0) {
				size = rand() % 9;
			}
		}
		size++;
		return size;
	}
	else if (free_to_go_number == 8) {
		if (is_free(4) == 1) {
			return 5;
		}
		else {
			while (size != 0 || size != 2 || size != 6 || size != 8) {
				if (is_free(size) == 0) {
					size = rand() % 9;
				}
			}
			size++;
			return size;
		}
	}
	else if (free_to_go_number == 7) {
		if
			(is_free(4) == 1) {
			

			return 5;
		}
		else {
			while (size != 0 || size != 2 || size != 6 || size != 8) {
				if (is_free(size) == 0) {
					size = rand() % 9;
				}
			}
			size++;
			return size;
		}
	}
	else if (free_to_go_number <= 6) {
		return where_to_go(free_to_go_number);
	}
}

int where_to_go(int free_to_go) {
	int to_go;
	for (int i = 0; i < 9; i += 3) {
		
		if (board[0 + i] == board[1 + i] && is_free(2 + i) == 1) {
			to_go = (2 + i) + 1;
			return to_go;
			
		}
		else if (board[1 + i] == board[2 + i] && is_free(0 + i)  == 1) {
			to_go = (0 + i)+1;
			return to_go;
		}
		else if (board[0 + i] == board[2 + i] && is_free(1 + i)  == 1) {
			to_go = (1 + i)+1;
			return to_go;
		}
	}

	//vertical win
	for (int i = 0; i < 3; i++) {
		if (board[0 + i] == board[3 + i] && is_free(6 + i)) {
			to_go = (6 + i)+1;
			return to_go;
		}
		else if (board[3 + i] == board[6 + i] && is_free(0 + i)) {
			to_go = (0 + i)+1;
			return to_go;
		}
		else if (board[0 + i] == board[6 + i] && is_free(3 + i)) {
			to_go = (3 + i)+1;
			return to_go;
		}		
	}

	//cross win

	if (board[0] == board[4] && is_free(8)) {
		return 9;
	}
	else if (board[4] == board[8] && is_free(0)) {
		return 1;
	}
	else if (board[2] == board[4] && is_free(6)) {
		return 7;
	}
	else if (board[6] == board[4] && is_free(2)) {
		return 3;
	}
	else {
		while (is_free(size) == 0) {
			size = rand() % 9;
		}
		size++;
		return size;
	}
}