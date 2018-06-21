#include <iostream>
typedef long long ll;

int main()
{
	ll num;
	std::cin >> num;
	num %= 10;
	if (num == 0)
		std::cout << "NO";
	else std::cout << num;
	return 0;
}

