#include <iostream>

using namespace std;

int prime[1000000];
int pn = 0;
bool check[1000001] = { false };
int n = 1000000;

int main()
{
	for (int i = 2; i < n; i++)
	{
		if (check[i] == false)
		{
			prime[pn++] = i;
			for (int j = i * 2; j < n; j = j + i)
			{
				check[j] = true;
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x;
		cin >> x;
		int cnt = 0;
		for (int j = 2; j <= x / 2; j++)
		{
			if (check[j] == false && check[x - j] == false)
				cnt++;
		}
		cout << cnt << '\n';
	}
}