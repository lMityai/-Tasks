#include <iostream>
#include <ctime>

using  namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	bool chis = true;
	bool m;
	int pred;
	srand(time(NULL));

	while (chis) {
		int num = rand() % 101;
		m = false;
		for (int i = 0; i < 5; i++) {
			cin >> pred;
			if (pred < num) {
				cout << "Число больше" << endl;
			}
			else {
				if (pred > num) {
					cout << "Число меньше" << endl;
				}
				else {
					cout << "Вы угадали!" << endl;
					m = true;
					break;
				}
			}
		}
		if (!m) {
			cout << "Вы проиграли. Было загадано: " << num << endl;
		}
		cout << "Начать сначала? (1 - ДА )" << endl;
		cin >> pred;
		chis = pred == 1 ? true : false;
	}
	return 0;
}
