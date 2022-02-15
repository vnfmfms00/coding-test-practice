#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}
	
	vector<int> v1;

	for (int i = 0; i < n; i++)
	{
		sort(v[i].begin(), v[i].end());
		v1.push_back(v[i][0]); // �࿡�� ���� ���� ���� v1�� ����
	}
	
	sort(v1.begin(), v1.end());

	cout << v1[n - 1] << endl; // �࿡�� ���� ���� ������ ��Ƴ��� vector v1���� ���� ū �� ���
}