#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> v;
void go(vector<int>& a, int idx, int cnt) // cnt�� ���� v�� �� ����, idx�� ������ ���� �����ϴ� �ε���
{
	// ���� ����
	if (cnt == 6)
	{
		// ���
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

	// �Ұ���
	if (idx == a.size())
		return;
	
	// idx�� �ش��ϴ� �� ����
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