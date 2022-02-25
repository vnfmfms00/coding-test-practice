#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	// vector v에서 제일 큰 값을 제외한 나머지를 더한 값이 답이다.
	int max = 0;
	int total = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (max < v[i])
			max = v[i];

		total += v[i];
	}

	total -= max;

	cout << total << '\n';
}