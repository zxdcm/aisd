#include <iostream>

int main()
{
	short year;
	std::cin >> year;
	if ((year % 400 == 0) | (year % 4 == 0 && year % 100 != 0))
		std::cout << "YES";
	else std::cout << "NO";
	return 0;
}