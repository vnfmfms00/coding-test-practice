#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> lotto;
void go(vector<int> a, int index, int cnt)
{
	if (cnt == 6)
	{
		// Ãâ·Â
		for (int i = 0; i < lotto.size(); i++)
		{
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return;
	}

	if (index >= a.size())
		return;

	lotto.push_back(a[index]);
	go(a, index + 1, cnt + 1);
	lotto.pop_back();
	go(a, index + 1, cnt);
}

int main()
{
	while (true)
	{
		int k;
		cin >> k;
		if (k == 0)
			break;

		vector<int> v(k, 0);
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}

		go(v, 0, 0);
		cout << '\n';
	}
}