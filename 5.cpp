#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

const ll INF = 1000000000000;

int main()
{
	ll n, m;
	std::cin >> n;
	std::cin >> m;
	std::vector<std::vector<std::pair<ll, ll>>> graph(n);
	for(ll i = 0; i<n; ++i)
		graph.push_back(std::vector<std::pair<ll, ll>>());

	for (ll i = 0; i < m; ++i)
	{
		ll from, to, weight;
		std::cin >> from;
		std::cin >> to;
	    std::cin >> weight;
		from--;
		to--;
		graph[from].push_back(std::make_pair(to, weight));
		graph[to].push_back(std::make_pair(from, weight));
	}
	ll from, stock;
	std::cin >> from;
	std::cin >> stock;
	from--;
	stock--;
	std::vector<ll> d(n, INF);
	d[from] = 0;
	std::set<std::pair<ll, ll>> q;
	q.insert(std::make_pair(d[from], from));
	while (!q.empty()) {
		ll v = q.begin()->second;
		q.erase(q.begin());

		for (ll j = 0; j < graph[v].size(); ++j)
		{
			ll to = graph[v][j].first,
				len = graph[v][j].second;
			if (d[v] + len < d[to])
			{
				q.erase(std::make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(std::make_pair(d[to], to));
			}
		}

	}
	std::cout << d[stock] << std::endl;
	return 0;
}