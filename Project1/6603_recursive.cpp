#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;
void go(vector<int>& a, int idx, int cnt) // cnt는 현재 v에 들어간 개수, idx는 넣을지 말지 결정하는 인덱스
{
	// 정답 가능
	if (cnt == 6)
	{
		// 출력
		for (int i = 0; i < 6; i++)
		{
			if (i == 5)
				cout << v[i];
			else
				cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 불가능
	if (idx == a.size())
		return;
	
	// idx에 해당하는 수 넣음
	v.push_back(a[idx]);
	go(a, idx + 1, cnt + 1);
	v.pop_back();
	go(a, idx + 1, cnt);
}

int main()
{
	while (true)
	{
		cin >> k;
		if (k == 0)
			return 0;

		vector<int> v(k, 0);
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
		}

		go(v, 0, 0);
		cout << '\n';
	}
}