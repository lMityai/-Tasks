#ifndef HEADER_H //от повторного 
#define HEADER_H
enum Status {
	PLAY,
	USER_WIN,
	BOT_WIN,
	NOT_WIN
};
struct Game {
	char bord[3][3];
	bool isUserTurn;
	char userChar;
	char botChar;
	Status status;
};
Game initGame(char userChar);
void updateDisplay(const Game game);
void botTurn(Game* game);
void userTurn(Game* game);
bool updateGame(Game* game);
#endif