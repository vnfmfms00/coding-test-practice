#include <iostream>
#include <algorithm>

using namespace std;
int maxInt = 2147483647;

int count2(int x)
{
	int cnt = 0;

	for (int i = 2; i <= x; i = i * 2)
	{
		cnt += x / i;

		if (i > maxInt / 2.0) break;
	}

	return cnt;
}

int count5(int x)
{
	int cnt = 0;

	for (int i = 5; i <= x; i = i * 5)
	{
		cnt += x / i;
		//intMax / 5 > i 그냥 리턴

		if (i > maxInt / 5.0) break;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int cnt5 = count5(n) - count5(n - m) - count5(m); // 5의 개수
	int cnt2 = count2(n) - count2(n - m) - count2(m); // 2의 개수
	int result = min(cnt2, cnt5);
	cout << result << '\n';
}