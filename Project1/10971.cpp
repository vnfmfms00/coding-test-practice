#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	vector<int> visit;
	for (int i = 0; i < n; i++)
	{
		visit.push_back(i);
	}

	int min = INT_MAX;
	do
	{
		int cost = 0;
		bool canTravel = true;
		for (int i = 0; i < n; i++)
		{
			// 마지막 여행지에서 첫번째 여행지로
			if (i == n - 1)
			{
				if (v[visit[i]][visit[0]] == 0)
				{
					canTravel = false;
					break;
				}
				else
					cost += v[visit[i]][visit[0]];
			}
			// 나머지 여행지간 이동
			else
			{
				if (v[visit[i]][visit[i + 1]] == 0)
				{
					canTravel = false;
					break;
				}
				else
					cost += v[visit[i]][visit[i + 1]];
			}
			
		}

		if (canTravel == true)
		{
			if (min > cost)
				min = cost;
		}
	} while (next_permutation(visit.begin(), visit.end()));

	cout << min << '\n';
}