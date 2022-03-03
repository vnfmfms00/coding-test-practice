#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int a, b, d;
	cin >> a >> b >> d;

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

	v[a][b] = 2; // 방문한 칸
	cnt++;

	while (true)
	{
		bool isFound = false; // 가보지 않은칸을 발견 했는가?

		// 네방향 탐색
		for (int i = 0; i < 4; i++)
		{
			d--;
			if (d < 0)
				d = 3;

			int t;
			switch (d)
			{
			case 0:
				t = a - 1;
				if (v[t][b] == 0)
				{
					a--;
					v[a][b] = 2;
					cnt++;
					isFound = true;
				}
				break;
			case 1:
				t = b + 1;
				if (v[a][t] == 0)
				{
					b++;
					v[a][b] = 2;
					cnt++;
					isFound = true;
				}
				break;
			case 2:
				t = a + 1;
				if (v[t][b] == 0)
				{
					a++;
					v[a][b] = 2;
					cnt++;
					isFound = true;
				}
				break;
			case 3:
				t = b - 1;
				if (v[a][t] == 0)
				{
					b--;
					v[a][b] = 2;
					cnt++;
					isFound = true;
				}
				break;
			}

			if (isFound) // 발견 했으면 다음 위치에서 갈 곳 정함
				break;
		}
		
		if (!isFound)
		{
			// 모두 가본칸이거나 바다로 되어있으면 방향유지한 채 한칸 뒤로
			switch (d)
			{
			case 0:
				a++;
				break;
			case 1:
				b--;
				break;
			case 2:
				a--;
				break;
			case 3:
				b++;
				break;
			}

			if (v[a][b] == 1) // 뒤쪽방향이 바다이면 움직임 멈춤
				break;
		}
	}

	cout << cnt << '\n';
}