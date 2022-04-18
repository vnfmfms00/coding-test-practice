#include <iostream>
#include <vector>

using namespace std;

int n, s;
int cnt = 0;
void go(vector<int> a, int idx, int sum)
{
	if (idx >= a.size())
	{
		if (sum == s)
			cnt++;
		return;
	}
	
	go(a, idx + 1, sum + a[idx]);
	go(a, idx + 1, sum);
}

int main()
{
	cin >> n >> s;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	if (s == 0)
		cnt -= 1;
	go(v, 0, 0);
	cout << cnt << '\n'; 
}