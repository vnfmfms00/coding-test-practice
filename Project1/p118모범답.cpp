#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int x, y, d;
	cin >> x >> y >> d;

	int cnt = 0;
	vector<vector<int>> v(n, vector<int>(m, 0)); // n x m vector

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			v[i][j] = x;
		}
	}

	v[x][y] = 2; // 방문한 칸
	cnt++;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int turnTime = 0; // 회전한 횟수

	while (true)
	{
		// 왼쪽 회전
		d--;
		if (d < 0)
			d = 3;

		int nx = x + dx[d];
		int ny = y + dy[d];

		// 회전하고 정면이 가보지 않은 곳이라면
		if (v[nx][ny] == 0)
		{
			v[nx][ny] = 2;
			x = nx;
			y = ny;
			cnt++;
			turnTime = 0;
		}
		// 가본곳 이거나 바다라면
		else
			turnTime++;

		// 네방향 모두 갈수 없다면
		if (turnTime == 4)
		{
			nx = x - dx[d];
			ny = y - dy[d];
			// 뒤쪽이 바다라 갈수 없다면
			if (v[nx][ny] == 1)
				break;
			else
			{
				x = nx;
				y = ny;
				turnTime = 0;
			}
		}
	}

	cout << cnt << '\n';
}