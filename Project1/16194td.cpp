#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int d[1001] = { 0 };
vector<int> p;

int go(int x)
{
	if (d[x] > 0) return d[x];

	d[x] = INT_MAX;
	for (int i = 0; i < x; i++)
	{
		int temp;
		if (i == 0)
		{
			temp = p[x];
		}
		else
			temp = go(i) + p[x - i];

		d[x] = min(temp, d[x]);
	}
	return d[x];
}

int main()
{
	int n;
	cin >> n;
	p.push_back(0); // 0

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		p.push_back(k); // 1~n
	}

	cout << go(n);
}

