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

	v[a][b] = 2; // �湮�� ĭ
	cnt++;

	while (true)
	{
		bool isFound = false; // ������ ����ĭ�� �߰� �ߴ°�?

		// �׹��� Ž��
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

			if (isFound) // �߰� ������ ���� ��ġ���� �� �� ����
				break;
		}
		
		if (!isFound)
		{
			// ��� ����ĭ�̰ų� �ٴٷ� �Ǿ������� ���������� ä ��ĭ �ڷ�
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

			if (v[a][b] == 1) // ���ʹ����� �ٴ��̸� ������ ����
				break;
		}
	}

	cout << cnt << '\n';
}