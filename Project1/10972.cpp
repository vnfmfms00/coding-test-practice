#include <iostream>
#include <vector>

using namespace std;
bool next_permutation(vector<int> &a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i])
	{
		i -= 1;
	}
	if (i <= 0)
		return false;

	int j = n - 1;
	while (a[i - 1] >= a[j])
	{
		j -= 1;
	}

	swap(a[i - 1], a[j]);
	j = n - 1;

	while (i < j)
	{
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
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

	if (next_permutation(v, n) == true)
	{
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else
		cout << -1 << '\n';
}