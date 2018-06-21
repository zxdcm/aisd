#include <iostream>
typedef long long ll;

int main()
{
	ll n=0;
	std::cin>>n;
	ll max1, max2, min1, min2, temp;
	max1 = max2 = min1 = min2 = temp = 0;
	for (ll i = 0; i < n; ++i) {   
		std::cin >> temp;
		if (temp > 0)
		{
			if (temp > max1) {
				max2 = max1;
				max1 = temp;
				continue;
			}
			if (temp > max2)
				max2 = temp;
		}
		else
		{
			if (temp < min1) {
				min2 = min1;
				min1 = temp;
				continue;
			}
			if (temp < min2)
				min2 = temp;
		}
	}
	if (min2 == 0 && max2 == 0) {
		std::cout << max1 * min1;
		return 0;
	}
	max1 *= max2;
	min1 *= min2;
	if (max1 > min1) {
		std::cout << max1;
	}
	else std::cout << min1;
    return 0;
}

