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

	v[x][y] = 2; // �湮�� ĭ
	cnt++;

	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int turnTime = 0; // ȸ���� Ƚ��

	while (true)
	{
		// ���� ȸ��
		d--;
		if (d < 0)
			d = 3;

		int nx = x + dx[d];
		int ny = y + dy[d];

		// ȸ���ϰ� ������ ������ ���� ���̶��
		if (v[nx][ny] == 0)
		{
			v[nx][ny] = 2;
			x = nx;
			y = ny;
			cnt++;
			turnTime = 0;
		}
		// ������ �̰ų� �ٴٶ��
		else
			turnTime++;

		// �׹��� ��� ���� ���ٸ�
		if (turnTime == 4)
		{
			nx = x - dx[d];
			ny = y - dy[d];
			// ������ �ٴٶ� ���� ���ٸ�
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