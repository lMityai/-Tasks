#include <iostream>
#include <set>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double m, x, v, t, a;
	double g = -9.8;
	std::cout << "Введите x, v, t." << std::endl;
	std::cin >> x>> v>> t;
	a = g * t * t * 1 / 2;
	m = x + v * t + a;
	std::cout << "Ответ: x(t)=" << m << std::endl;

	a = 1 / 2 * g * t * t;
	m = x + v * t + a;
	std::cout << "Ответ: x(t)=" << m << std::endl;
	return 0;
}

