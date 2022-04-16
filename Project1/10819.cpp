#include <iostream>
#include <vector>
#include <algorithm>

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

	sort(v.begin(), v.end()); // 오름차순 정렬
	int max = -1;
	do
	{
		int result = 0;
		for (int i = 1; i < n; i++)
		{
			result += abs(v[i - 1] - v[i]);
		}
		if (result > max)
			max = result;
	} while (next_permutation(v.begin(), v.end()));

	cout << max << '\n';
}