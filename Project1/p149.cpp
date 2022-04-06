// 못풀었음. 나중에 다시 풀것

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> graph(1000, vector<int>(1000, 0));

bool dfs(int x, int y)
{
	if (x <= -1 || x >= n || y <= -1 || y >= m)
		return false;
	if (graph[x][y] == 0)
	{
		graph[x][y] = 1;
		dfs(x, y - 1);
		dfs(x, y + 1);
		dfs(x - 1, y);
		dfs(x + 1, y);
		return true;
	}
	return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			graph[i][j] = s[j] - '0';
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfs(i, j) == true)
				result += 1;
		}
	}

	cout << result << '\n';
}