#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[4] = { 25, 10, 5, 1 };
	int len = sizeof arr / sizeof arr[0];

	int n;
	cin >> n;

	vector<int> v;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int idx = 0;
		vector<int> v1(4, 0);

		while(true)
		{
			// 거스름돈이 현재 비교하고있는 돈 단위보다 크면 나눈 몫을 저장
			if (v[i] >= arr[idx])
			{
				v1[idx] = (v[i] / arr[idx]); // 몫 저장
				v[i] %= arr[idx]; // 나머지를 거스름돈으로 갱신
			}
				
			else // 작으면 다음 돈 단위와 비교
				idx++;

			if (idx >= len) // 비교 끝
				break;
		}

		// 출력
		for (int j = 0; j < v1.size(); j++)
		{
			cout << v1[j] << ' ';
		}
		cout << '\n';
	}
	
}