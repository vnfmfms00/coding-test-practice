#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	int plus; // 0
	int minus; // 1
	int mul; // 2
	int div; // 3
	cin >> plus >> minus >> mul >> div;

	vector<int> op;
	for (int i = 0; i < plus; i++)
	{
		op.push_back(0);
	}
	for (int i = 0; i < minus; i++)
	{
		op.push_back(1);
	}
	for (int i = 0; i < mul; i++)
	{
		op.push_back(2);
	}
	for (int i = 0; i < div; i++)
	{
		op.push_back(3);
	}

	int min = INT_MAX;
	int max = INT_MIN;
	do
	{
		int result = num[0];
		for (int i = 1; i < n; i++)
		{
			if (op[i - 1] == 0)
			{
				result += num[i];
			}
			else if (op[i - 1] == 1)
			{
				result -= num[i];
			}
			else if (op[i - 1] == 2)
			{
				result *= num[i];
			}
			else if (op[i - 1] == 3)
			{
				result /= num[i];
			}
		}

		if (result > max)
			max = result;
		if (result < min)
			min = result;
	} while (next_permutation(op.begin(), op.end()));

	cout << max << '\n' << min << '\n';
}