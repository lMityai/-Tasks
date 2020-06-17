#include <iostream>
#include <time.h>
#include "header.h" 
using namespace std;
int main() {
	 int hwoper;
	Game game
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(NULL));//чтоб первый всегда не ходил
	hwoper = rand() % 2;

	if (hwoper==1) {
		game.isUserTurn = true;
		game.userChar = 'X';
		game.botChar = 'O';
		game.status = PLAY;
	}
	else {
		game.isUserTurn = false;
		game.userChar = 'O';
		game.botChar = 'X';
		game.status = PLAY;
	}
	while (!updateGame(&game)) {//пока игра в работе
		if (game.isUserTurn) {
			userTurn(&game);
		}
		else {
			botTurn(&game);
		}
		updateDisplay(game);
	}

	switch (game.status) {
	case USER_WIN: cout << "Вы победили"; break;
	case BOT_WIN: cout << "Bы проиграли"; break;
	case NOT_WIN: cout << "Ничья"; break;
	}return 0;
}