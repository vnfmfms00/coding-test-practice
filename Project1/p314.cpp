#include <iostream>
#include <vector>
#include <algorithm>

// �� ������ �����س��°� ������� ���߿� �ٽ�Ǯ���

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

	sort(v.begin(), v.end());

	int target = 1;

	for (int i = 0; i < n; i++)
	{
		if (target < v[i]) // target�� �����Ҽ��ִ��� Ȯ��. target�� ����� ����� ������ ����
			break;

		target += v[i]; // ���� Ÿ�� ������Ʈ(v[i]�� target-1������ ����� �ִ�)
	}

	cout << target << '\n';
	
}