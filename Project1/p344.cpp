// 시간초과. 못풀겠음
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;

vector<vector<int>> graph(200, vector<int>(200, 0));
vector<vector<int>> check(200, vector<int>(200, 0));

void bfs(int _x, int _y, int _m)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (graph[nx][ny] != 0)
			continue;

		if (graph[nx][ny] == 0)
		{
			graph[nx][ny] = _m;
		}
	}

	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << graph[i][j];
		}
		cout << '\n';
	}*/

	// 공간 벗어나면 무시
	// 다른 바이러스가 있으면 무시
	// 0일경우에만 m으로 바꿈
}

int main()
{
	int k;
	cin >> n >> k;

	vector<int> count(k + 1, 0);
	vector<int> count1(k + 1, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			graph[i][j] = x;
			for (int m = 1; m <= k; m++)
			{
				if (m == x)
					count[m] += 1;
			}
		}
	}

	int s, x, y;
	cin >> s >> x >> y;

	int plus = 0;
	for (int t = 0; t < s; t++)
	{
		for (int m = 1; m <= k; m++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (graph[i][j] == m && count1[m] < count[m])
					{
						// bfs
						bfs(i, j, m);
						//cout << i << j << '\n';
						count1[m]++;
					}
				}
			}

			count1[m] = 0;
			count[m] = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (graph[i][j] == m)
					{
						// bfs
						count[m]++;
					}
				}
			}
		}
	}
	cout << graph[x - 1][y - 1] << '\n';
}