

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int a, b, c;
	cin>> a >> b;
	c = a;
	a = b;
	b = c;
	cout<< a <<" "<< b << ::std::endl;
    a = b - a;
	b = b - a;
	a = b + a;
	cout << a << " " << b << ::std::endl;

	return 0;
}