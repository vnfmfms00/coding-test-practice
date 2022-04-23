#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> op;
	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;

		for (int j = 0; j < x; j++)
		{
			op.push_back(i); // +: 0, -: 1, *:2, /:3 개수만큼 push
		}
	}

	int maxValue = INT_MIN;
	int minValue = INT_MAX;
	do
	{
		int result = v[0];
		for (int i = 0; i < op.size(); i++)
		{
			if (op[i] == 0)
				result += v[i + 1];
			else if (op[i] == 1)
				result -= v[i + 1];
			else if (op[i] == 2)
				result *= v[i + 1];
			else if (op[i] == 3)
				result /= v[i + 1];
		}

		if (result < minValue)
			minValue = result;
		if (result > maxValue)
			maxValue = result;

	} while (next_permutation(op.begin(), op.end()));

	cout << maxValue << '\n' << minValue << '\n';
}