#include <iostream>
#include <vector>

typedef long long ll;

std::vector<std::vector<ll>> matrix;
std::vector<std::vector<ll>> identity;
ll n, m;

#define mod (ll)(1000000007)


std::vector<std::vector<ll>> multiply()
{
	std::vector<std::vector<ll>> ans(n, std::vector <ll>(n));
	for (ll i = 0; i < n; ++i)
		for (ll j = 0; j < n; ++j)
			for (ll k = 0; k < n; k++) 
				ans[i][j] = (ans[i][j] + (identity[i][k] * matrix[k][j]) % mod) % mod;
	return ans;
}

std::vector<std::vector<ll>> square()
{
	std::vector<std::vector<ll>> ans(n, std::vector <ll>(n));
	for (ll i = 0; i < n; ++i)
		for (ll j = 0; j < n; ++j)
			for (ll k = 0; k < n; k++) 
				ans[i][j] = (ans[i][j] + (matrix[i][k] * matrix[k][j]) % mod) % mod;
	return ans;
}


int main()
{
	ll from, to, a, b, l;
	std::cin >> n >> m >> from >> to >> l;
	identity = std::vector<std::vector<ll>>(n, std::vector <ll>(n));
	matrix = std::vector<std::vector<ll>>(n, std::vector <ll>(n));

	for (ll i = 0; i < n; i++)
		identity[i][i] = 1;

	for (ll i = 0; i < m; ++i)
	{
		std::cin >> a >> b;
		--a;
		b--;
		if (a == b)
			matrix[a][b] += 2;
		else matrix[a][b] += 1;
		matrix[b][a] = matrix[a][b];
	} 

	while (l)
	{
		if (l % 2)
			identity = multiply();
		matrix = square();
		l /= 2;
	}
	--to, --from;
	std::cout<< (identity[from][to] % mod) << std::endl;
	return 0;
}