#include <iostream>
#include <stack>
#include <algorithm>

typedef long long ll;

int main()
{
	ll n;
	std::cin >> n;
	std::stack<ll> st;
	ll x = 0;
	ll in = 0;
	for (ll i = 0; i < n; ++i)
	{
		std::cin >> in;
		if (st.empty() || st.top() > in)
			st.push(in);
		else 
		{
			if (st.top() == in)
				continue;
			ll value = st.top();
			st.pop();
			while(!st.empty() && st.top() <= in)
			{
				x += st.top() - value;
				value = st.top();
				st.pop();
			}
			x += in - value;
			st.push(in);
		}
	}
	if (!st.empty())
	{
		ll val = st.top();
		st.pop();
		while (!st.empty())
		{
			x += st.top() - val;
			val = st.top();
			st.pop();
		}
	}

	std::cout << x << std::endl;

	return 0;
}