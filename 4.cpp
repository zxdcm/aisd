#include <iostream>
#include <vector>
#include <queue>

typedef int ll;

std::vector<std::vector<int>> visited;
ll n, m, end_x, end_y;
std::queue< std::pair< std::pair<ll, ll>, ll>> steps; // pair <x,y>, path_size

void add_steps(ll x, ll y, ll size)
{
	int arr[] = {
		x + 2, y + 1,
		x - 1, y + 2,
		x - 1, y - 2,
		x + 1, y + 2,
		x + 2, y - 1,
		x + 1, y - 2,
		x - 2, y + 1,
		x - 2, y - 1
	};
	size++;
	for (int i = 0, j = 1; i < 16; i += 2, j += 2)
		if ((arr[i] > -1 && arr[i] < n) && (arr[j] > -1 && arr[j] < m) && (visited[arr[i]][arr[j]] == -1 || visited[arr[i]][arr[j]] > size)) 
			steps.push(std::make_pair(std::make_pair(arr[i], arr[j]), size));
		
}

int main()
{
	std::cin >> n >> m >> end_x >> end_y;
	visited = std::vector<std::vector<int>>(n, std::vector<int>(m, -1));

	steps.push(std::make_pair(std::make_pair(0, 0), 0));
	while (!steps.empty())
	{
		std::pair<std::pair<ll, ll>, ll> cur = steps.front();
		steps.pop();
		if (visited[cur.first.first][cur.first.second] == -1) {
			add_steps(cur.first.first, cur.first.second, cur.second);
			visited[cur.first.first][cur.first.second] = cur.second;
		}
		if (cur.second < visited[cur.first.first][cur.first.second])
			add_steps(cur.first.first, cur.first.second, cur.second);
			visited[cur.first.first][cur.first.second] = cur.second;
	}
	end_x--;
	end_y--;
	if (visited[end_x][end_y] == -1)
		std::cout << "NEVAR";
	else std::cout << visited[end_x][end_y];
	return 0;
}