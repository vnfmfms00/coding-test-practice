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

	// vector v���� ���� ū ���� ������ �������� ���� ���� ���̴�.
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