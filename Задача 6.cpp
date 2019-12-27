#include <iostream>
#include <iomanip>
#include <cmath>



int main()
{
	double a, b, c;
	double desk;
	double kdesk;
	double x1, x2;
	double x;

	setlocale(LC_ALL, "Russian");

	std::cin >> a >> b >> c;
	if(a!=0){
		desk = b * b - 4 * a * c;
		if (desk < 0) {
			std::cout << "Корней нет" << std::endl;
		}
		else {
			kdesk = sqrt(desk);
			x1 = (-b + kdesk) / (2 * a);
			x2 = (-b - kdesk) / (2 * a);
			std::cout << "x1=" << x1 << " " << "x2=" << x2 << std::endl;
		}
	}
	else {		// b * x + c = 0
		if (b != 0) {
			x = (-c / b);
			std::cout << "x=" << x << std::endl;
		}
		else { // 0 *x^2 + 0 * x + 0 = 0
			if (c != 0) {
				std::cout << "Корней нет" << std::endl;
			}
			else {
				std::cout << "Бесконечное множество корней " << std::endl;

			}
		}
	}

	system("pause");
	return 0;
}