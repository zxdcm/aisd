#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

int main()
{
	std::string str;
	ll q_n, l, r;
	std::cin >> str >> q_n;
	ll len = str.size();
	std::vector<std::pair<ll,ll>> l_r(len, std::make_pair(0,0));
	for (ll i = 0; i < q_n; ++i)
	{
		std::cin >> l >> r;
		if (l > r)
			std::swap(l, r);
		l_r[--l].first ++;
		l_r[--r].second ++;
	}
	ll l_len = len - 1; 
	//char diff = 'a' - 'A'; 
	for (ll i = 0; i < len; ++i)
	{
		if (l_r[i].first & 1)  // 2 -> 10; 3 -> 11 => even nums have 0. odd nums have 1. Instead of % 
			islower(str.at(i)) ? str.at(i) = toupper(str.at(i)) : str.at(i) = tolower(str.at(i));
		if (i < l_len)
			l_r[i + 1].first += l_r[i].first - l_r[i].second; // if l_r[i].second == 0 => somewhere opened queries
	}
	std::cout << str;
	return 0;
}