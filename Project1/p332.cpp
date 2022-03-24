#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// ���� ���ϴ°� �����ؼ� ���� ���ϴ¹� ���۸� �������.

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> city(n, vector<int>(n, 0));
	vector<vector<int>> house;
	vector<vector<int>> chicken;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			city[i][j] = x;
			vector<int> v;
			v.push_back(i);
			v.push_back(j);
			if (x == 1)
			{
				house.push_back(v);
			}
			else if (x == 2)
			{
				chicken.push_back(v);
			}
		}
	}

	// nextpermutation�� �̿��� ����
	// ��ü n���� ���ҵ� �߿��� m���� �̴� ����(=nCm)�� ���Ѵٸ� n���� ���� ���ҿ� 1�� m�� 0�� �������� n-m�� ����־ ������ ������ 1�� �ش��ϴ� �ε����� �������� �ȴ�.
	vector<int> ind;

	// ������� �ϴ� ġŲ�� ���� m���� 1
	for (int i = 0; i < m; i++)
	{
		ind.push_back(1);
	}
	// ������ ġŲ�� ���� chicken - m��0
	for (int i = 0; i < chicken.size() - m; i++)
	{
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end());
	int minChickenDistance = INT_MAX;
	do
	{
		vector<vector<int>> combination;
		for (int i = 0; i < ind.size(); i++)
		{
			if (ind[i] == 1)
			{
				combination.push_back(chicken[i]);
			}
		}

		int chickenDistance = 0; // ġŲ �Ÿ�
		// �Ÿ� ����
		for (int i = 0; i < house.size(); i++)
		{
			int minDistance = INT_MAX;
			// ���� (1,1), (1,2)
			for (int j = 0; j < combination.size(); j++)
			{
				int dist = abs(house[i][0] - combination[j][0]) + abs(house[i][1] - combination[j][1]);

				// ������ ���� ����� ġŲ�� �Ÿ� ����
				if (dist < minDistance)
					minDistance = dist;
			}

			chickenDistance += minDistance; // ������ ���� ����� ġŲ�� �Ÿ� ������
		}
		

		if (chickenDistance < minChickenDistance)
			minChickenDistance = chickenDistance;

	} while (next_permutation(ind.begin(), ind.end()));

	cout << minChickenDistance << '\n';

}