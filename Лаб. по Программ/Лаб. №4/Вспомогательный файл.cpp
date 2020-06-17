#include <iostream>
#include "header.h"
using namespace std;
Game game;
void updateDisplay(const Game game) {
	system("cls");
	cout << " _____0___1___2_" << endl;
	cout << " 0 " << " | " << game.bord[0][0] << " | " << game.bord[0][1] << " | " << game.bord[0][2] << " | " << endl;
	cout << "_________________" << endl;
	cout << " 1 " << " | " << game.bord[1][0] << " | " << game.bord[1][1] << " | " << game.bord[1][2] << " | " << endl;
	cout << "_________________" << endl;
	cout << " 2 " << " | " << game.bord[2][0] << " | " << game.bord[2][1] << " | " << game.bord[2][2] << " | " << endl;
	cout << "_________________" << endl;
}

void botTurn(Game* game) {
	bool CLEAR = true, BNCLEAR = false;
	int str;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (game->bord[i][j] == game->userChar || game->bord[i][j] == game->botChar) {
				CLEAR = false;
			}
		}
	}
	if (CLEAR) {
		game->bord[1][1] = game->botChar; game->isUserTurn = true;
	}
	else {
		for (int i = 0; i < 3; ++i) { 
			str = 0;
			if (game->bord[i][0] == game->userChar) {
				str++;
			}
			if (game->bord[i][1] == game->userChar) {
				str++;
			}
			if (game->bord[i][2] == game->userChar) { 
				str++; 
			}
			if (str > 1) {
				for (int j = 0; j < 3; ++j) { //пров столбц
					if (game->bord[i][j] != game->userChar && game->bord[i][j] != game->botChar) {
						game->bord[i][j] = game->botChar;game->isUserTurn = true;BNCLEAR = true;return;
					}
				}
				break;
			}
		}
		if (!BNCLEAR) {
			for (int j = 0; j < 3; ++j) { //чекаем столб
				str = 0;
				if (game->bord[0][j] == game->userChar) {
					str++;
				}
				if (game->bord[1][j] == game->userChar) {
					str++;
				}
				if (game->bord[2][j] == game->userChar) {
					str++;
				}
				if (str > 1) {
					for (int i = 0; i < 3; ++i) { 
						if (game->bord[i][j] != game->userChar && game->bord[i][j] != game->botChar) {
							game->bord[i][j] = game->botChar;game->isUserTurn = true;BNCLEAR = true;return;
						}
					}
					break;
				}
			}
		}
		if (!BNCLEAR) {//диагональ 00 11 22
			str = 0;
			for (int i = 0; i < 3; ++i) {
				if (game->bord[i][i] == game->userChar) {
					str++;
				}
			}
			if (str > 1) {
				for (int i = 0; i < 3; ++i) {
					if (game->bord[i][i] != game->userChar && game->bord[i][i] != game->botChar) {
						game->bord[i][i] = game->botChar;
						game->isUserTurn = true;
						BNCLEAR = true;
						return;
					}
				}
			}
		}
		if (!BNCLEAR) {//диагонал 02 11 20
			str = 0;
			if (game->bord[0][2] == game->userChar) {
				str++;
			}
			if (game->bord[1][1] == game->userChar) {
				str++;
			}
			if (game->bord[2][0] == game->userChar) {
				str++;
			}
			if (str > 1) {
				if ((game->bord[0][2] != game->userChar && game->bord[0][2] != game->botChar) && !BNCLEAR) {
					game->bord[0][2] = game->botChar;game->isUserTurn = true;BNCLEAR = true;return;
				}
				if ((game->bord[1][1] != game->userChar && game->bord[1][1] != game->botChar) && !BNCLEAR) {
					game->bord[1][1] = game->botChar;game->isUserTurn = true;BNCLEAR = true;return;
				}
				if ((game->bord[2][0] != game->userChar && game->bord[2][0] != game->botChar) && !BNCLEAR) {
					game->bord[2][0] = game->botChar;game->isUserTurn = true;BNCLEAR = true;return;
				}
			}
		}
		if (!BNCLEAR) {//рандомный 
			while (true) {
				int i = rand() % 3;
				int j = rand() % 3;
				if (game->bord[i][j] != game->userChar && game->bord[i][j] != game->botChar) {
					game->bord[i][j] = game->botChar;game->isUserTurn = true;BNCLEAR = true;break;
				}
			}

		}

	}

}
void userTurn(Game* game) {
	int i, j;
	while (true) {
		setlocale(LC_ALL, "rus");
		cout << "[строка][столбец]"; cin >> i >> j;
		if ((i >= 0) && (i <= 2) && (j >= 0) && (j <= 2)) {
			if ((game->bord[i][j] != game->userChar) && (game->bord[i][j] != game->botChar)) {
				game->bord[i][j] = game->userChar;game->isUserTurn = false;break;
			}
			else cout << "Нельзя так " << endl;
		}
		else cout << "Нельзя так " << endl;
	}
}
bool updateGame(Game* game) {
	bool konec = true;
	char xoro;
	int str;
	if (!game->isUserTurn) xoro = game->userChar;
	else xoro = game->botChar;
	for (int i = 0; i < 3; ++i) {//строки
		str = 0;
		for (int j = 0; j < 3; ++j) {
			if (game->bord[i][j] == xoro) str++;
		}
		if (str == 3) {
			if (!game->isUserTurn) game->status = USER_WIN;
			else game->status = BOT_WIN;
			return konec;
		}
	}
	for (int j = 0; j < 3; ++j) {//ытолбы
		str = 0;
		for (int i = 0; i < 3; ++i) {
			if (game->bord[i][j] == xoro) str++;
		}
		if (str == 3) {
			if (!game->isUserTurn) game->status = USER_WIN;
			else game->status = BOT_WIN;
			return konec;
		}
	}
	str = 0;
	if (game->bord[0][0] == xoro) {
		str++;
	}
	if (game->bord[1][1] == xoro) {
		str++;
	}
	if (game->bord[2][2] == xoro) {
		str++;
	}
	if (str == 3) {
		if (!game->isUserTurn) game->status = USER_WIN;
		else game->status = BOT_WIN;return konec;
	}
	str = 0;
	if (game->bord[2][0] == xoro)  str++;
	if (game->bord[1][1] == xoro)  str++;
	if (game->bord[0][2] == xoro)  str++;
	if (str == 3) {
		if (!game->isUserTurn) game->status = USER_WIN;
		else game->status = BOT_WIN;return konec;
	}
	str = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if ((game->bord[i][j] != game->userChar) && (game->bord[i][j] != game->botChar)) {
				str++;
			}
		}
	}
	if (!str) {
		game->status = NOT_WIN;
		return konec;
	}
	else konec = false;
	return konec;
}
Game initGame(char userChar) {
	int first = rand() % 2;
	char botChar;
	if (userChar == 'X') botChar = 'O';
	else botChar = 'X';
	game.userChar = userChar;
	game.botChar = botChar;
	if (first) game.isUserTurn = true;
	else game.isUserTurn = false;
	game.status = PLAY;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			game.bord[i][j] = ' ';
		}
	}
	return game;
}