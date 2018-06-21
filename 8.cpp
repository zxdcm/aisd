#include <iostream>
#include <string>

int main()
{
	std::string str;
	std::cin >> str;
	int j = str.length();
	int answ = j;
	if (j == 1) {
		std::cout << -1;
		return 0;
	}
	j--;
	bool flag = true;
	char c = str[0];
	for (int i = 0; i <= j; ++i, j--) {
		if (str[i] != str[j])
		{
			std::cout << answ;
			return 0;
		}
		if (str[i] != c)
			flag = false;
	}
	if (flag == true)
		std::cout << "-1";
	else std::cout << answ - 1;
	return 0;
}