#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int d[1001] = { 0 };


int main()
{
	int n;
	cin >> n;
	vector<int> p(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	d[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		int min = INT_MAX;
		int temp = 0;
		for (int j = 1; j <= i; j++)
		{
			temp = (d[i - j] + p[j]);

			if (min > temp)
				min = temp;
		}
		d[i] = min;
	}

	cout << d[n] << '\n';
}