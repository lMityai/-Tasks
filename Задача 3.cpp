#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

{
		int a, b ;
	std::cout << "Введите a" << std::endl;
	std::cin >> a;
	std::cout << "Введите b" << std::endl;
	std::cin >> b;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
}

{
	double a, b;

	std::cout << "Введите a" << std::endl;
	std::cin >> a;
	std::cout << "Введите b" << std::endl;
	std::cin >> b;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
}

{
	int a;
	double b;
	std::cout << "Введите a" << std::endl;
	std::cin >> a;
	std::cout << "Введите b" << std::endl;
	std::cin >> b;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
}
{
	double a;
	int b;
	std::cout << "Введите a" << std::endl;
	std::cin >> a;
	std::cout << "Введите b" << std::endl;
	std::cin >> b;
	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
}

return 0;
	}