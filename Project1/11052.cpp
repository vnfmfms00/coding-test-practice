#include <iostream>
#include <vector>

using namespace std;

int d[1001] = { 0 };


int main()
{
	int n;
	cin >> n;
	vector<int> p(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	d[0] = 0;
	d[1] = p[0];

	for (int i = 2; i <= n; i++)
	{
		int max = 0;
		int temp = 0;
		for (int j = 0; j < i; j++)
		{
			temp = (d[i - j - 1] + p[j]);

			if (max < temp)
				max = temp;
		}
		d[i] = max;
	}

	cout << d[n] << '\n';
}