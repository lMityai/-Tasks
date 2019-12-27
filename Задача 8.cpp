#include <iostream>
using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	double a, b, c;
//	char n;
//	cin >> a >> n >> b;
//	if (n == '+')
//	{
//		c = a + b;
//		cout << "Ответ " << c << ::std::endl;
//	}
//	if (n == '-')
//	{
//		c = a - b;
//		cout << "Ответ " << c << ::std::endl;
//	}
//	if (n == '*')
//	{
//		c = a * b;
//		cout << "Ответ " << c << ::std::endl;
//	}
//	if (n == '/')
//	{
//		c = a / b;
//		cout << "Ответ " << c << ::std::endl;
//    }
//	return 0;
//}


int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b;
	char c;
	cin >> a >> b >> c;
	switch (c) {
	case'+':
		cout << a + b << endl;
		break;
	case'-':
		cout << a - b << endl;
		break;
	case'*':
		cout << a * b << endl;
		break;
	case'/':
		if (b == 0) cout << "Ошибка" << endl;
		else cout << a / b << endl;
	defauld:
		cout << "Введите коректный оператор" << endl;
	}
	return 0;
}