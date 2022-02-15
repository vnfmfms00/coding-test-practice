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
		v1.push_back(v[i][0]); // 행에서 가장 작은 수를 v1에 넣음
	}
	
	sort(v1.begin(), v1.end());

	cout << v1[n - 1] << endl; // 행에서 가장 작은 수들을 모아놓은 vector v1에서 가장 큰 수 출력
}