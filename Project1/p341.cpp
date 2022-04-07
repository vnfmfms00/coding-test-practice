// 못풀겠다

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;

void bfs(int _x, int _y, vector<vector<int>> _graph)
{
	vector<int> v;
	v.push_back(_x);
	v.push_back(_y);
	queue<vector<int>> q;
	q.push(v);

	while (!q.empty())
	{
		int x = q.front()[0];
		int y = q.front()[1];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny <= m)
				continue;

			if (_graph[nx][ny] == 1)
				continue;

			if (_graph[nx][ny] == 0)
			{
				_graph[nx][ny] = 2;
				vector<int> v1;
				v1.push_back(nx);
				v1.push_back(ny);
				q.push(v1);
			}
		}
		// 공간 벗어나면 무시
		// 벽이면 무시
		// 0일경우에만 2로 바꿈
	}

	int result = 0;
	// 0의 개수 셈
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (_graph[i][j] == 0)
				result += 1;
		}
	}

}

int main()
{

}