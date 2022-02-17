#include <iostream>
#include <vector>
#include <algorithm>

// 이 문제는 생각해내는게 어려워서 나중에 다시풀어볼것

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
		if (target < v[i]) // target을 만족할수있는지 확인. target을 만드는 방법이 없으면 종료
			break;

		target += v[i]; // 다음 타겟 업데이트(v[i]로 target-1까지는 만들수 있다)
	}

	cout << target << '\n';
	
}