#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// 조합 구하는게 생소해서 조합 구하는법 구글링 도움받음.

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

	// nextpermutation을 이용한 조합
	// 전체 n개의 원소들 중에서 m개를 뽑는 조합(=nCm)을 구한다면 n개의 벡터 원소에 1을 m개 0을 나머지인 n-m개 집어넣어서 순열을 돌리고 1에 해당하는 인덱스만 가져오면 된다.
	vector<int> ind;

	// 남기고자 하는 치킨집 개수 m개는 1
	for (int i = 0; i < m; i++)
	{
		ind.push_back(1);
	}
	// 나머지 치킨집 개수 chicken - m은0
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

		int chickenDistance = 0; // 치킨 거리
		// 거리 구함
		for (int i = 0; i < house.size(); i++)
		{
			int minDistance = INT_MAX;
			// 조합 (1,1), (1,2)
			for (int j = 0; j < combination.size(); j++)
			{
				int dist = abs(house[i][0] - combination[j][0]) + abs(house[i][1] - combination[j][1]);

				// 집에서 가장 가까운 치킨집 거리 구함
				if (dist < minDistance)
					minDistance = dist;
			}

			chickenDistance += minDistance; // 집에서 가장 가까운 치킨집 거리 더해줌
		}
		

		if (chickenDistance < minChickenDistance)
			minChickenDistance = chickenDistance;

	} while (next_permutation(ind.begin(), ind.end()));

	cout << minChickenDistance << '\n';

}