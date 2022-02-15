#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int arr[1000];
	int idx = 0;
	while (n--)
	{
		scanf("%d", &arr[idx]);
		idx++;
	}

	int max = INT_MIN;
	int max_idx = -1;
	int sec_max = INT_MIN;
	for (int i = 0; i < idx; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			max_idx = i;
		}
	}

	for (int i = 0; i < idx; i++)
	{
		if (max_idx == i)
			continue;

		if (sec_max < arr[i])
		{
			sec_max = arr[i];
		}
	}

	int total = 0;
	int cnt = 1;
	while (m--)
	{
		if (cnt % (k + 1) == 0)
			total += sec_max;
		else
			total += max;

		cnt++;
	}

	cout << total << endl;
	return 0;
}