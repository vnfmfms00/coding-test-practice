#include <iostream>
#include <string>

using namespace std;

// 나중에 다시 풀어볼것. 답 보고 풀었음
// 시각에 3이 포함 되있으면 true, 아니면 false
bool check(int h, int m, int s)
{
	if (h % 10 == 3 || m % 10 == 3 || m / 10 == 3 || s % 10 == 3 || s / 10 == 3)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				if (check(i, j, k))
					cnt++;
			}
		}
	}

	cout << cnt << '\n';
}