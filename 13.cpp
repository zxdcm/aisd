#include <iostream>
#include <vector>

typedef long long ll;

std::vector<char> used;
std::vector<std::vector<ll>> graph;

void dfs(int v) {
	used[v] = true;
	for (int i = 0; i < graph[v].size(); ++i)
		if (!used[graph[v][i]])
			dfs(graph[v][i]);
}

int main()
{
	ll n, m, x = 0;
	std::cin >> n;
	std::cin >> m;
	graph = std::vector<std::vector<ll>>(n);
	used = std::vector<char>(n);
	for (ll i = 0; i < m; ++i)
	{
		ll from, to;
		std::cin >> from;
		std::cin >> to;
		from--;
		to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 0; i < n; ++i)
	{
		if (!used[i]) {
			dfs(i);
			x++;
		}
	}
	if (x - 1 > 0)
		std::cout << -1 << std::endl; 
	else std::cout << m - n + 1 << std::endl; //n=m+1 tree attrib