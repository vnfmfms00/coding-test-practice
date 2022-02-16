#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}


	sort(v.begin(), v.end()); // 오름차순

	int result = 0; // 총 그룹 수
	int count = 0; // 현재 그룹에 들어가는 모험가 수

	for (int i = 0; i < n; i++)
	{
		count += 1; // 일단 현재 그룹에 인원 추가
		if (count >= v[i]) // 현재 그룹 인원이 현재의 공포도보다 같거나 높으면 그룹 결성 완료
		{
			result += 1; // 총 그룹 수 증가
			count = 0; // 현재 그룹 초기화
		}
	}

	cout << result << endl;
	return 0;
}