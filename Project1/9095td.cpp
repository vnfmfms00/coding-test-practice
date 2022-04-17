#include <iostream>

using namespace std;
int d[11];

int go(int x)
{
	if (d[x] > 0)
		return d[x];

	if (x <= 1)
	{
		d[x] = 1;
	}
	else if (x == 2)
	{
		d[x] = 2;
	}
	else
	{
		d[x] = go(x - 1) + go(x - 2) + go(x - 3);
	}
	
	return d[x];
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << go(n) << '\n';
	}
}