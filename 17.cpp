#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
	long n,num;
	bool n1, n2, n3, n1n2, n1n3, n2n3, n1n2n3;
    n1 = n2 = n3 = n1n2 = n1n3 = n2n3 = n1n2n3 = false;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> num;
		if (num == 1021)
			n1 = true;
		else if (num == 1031)
			n2 = true;
		else if (num == 1033)
			n3 = true;
		else if (num == 1021 * 1031)
			n1n2 = true;
		else if (num == 1021 * 1033)
			n1n3 = true;
		else if (num == 1031 * 1033)
			n2n3 = true;
		else if (num == 1087388483)
			n1n2n3 = true;
	}
	if ((n1 && n2 && n3) | (n1n2 && n3) | (n1n3 && n2) | (n2n3 && n1) |(n1n2n3))
		std::cout << "YES";
	else
		std::cout << "NO";
	system("pause");
	return 0;
}