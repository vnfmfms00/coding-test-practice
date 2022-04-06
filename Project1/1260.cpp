#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[1000];
vector<bool> visited(1000, false);
vector<bool> visited_bfs(1000, false);

void dfs(int x)
{
	visited[x] = true;
	cout << x << ' ';

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (visited[y] == false)
			dfs(y);
	}
}

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited_bfs[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (visited_bfs[y] == false)
			{
				q.push(y);
				visited_bfs[y] = true;
			}
		}
	}
}

int main()
{
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << '\n';
	bfs(v);

}