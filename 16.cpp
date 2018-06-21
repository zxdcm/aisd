
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	long num;
	std::cin >> num;
	std::vector<char> digits;
	do
		digits.push_back(num % 10);
	while (num /= 10);
	std::reverse(digits.begin(), digits.end());
	if (std::next_permutation(digits.begin(), digits.end())){
		for (num = 0; num < digits.size(); ++num)  //num ~ i;
			std::cout << (int)digits[num];
		return 0;
	}
	else std::cout << "-1";
	return 0;
}