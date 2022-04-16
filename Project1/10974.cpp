#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(i + 1);
	}

	do {
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end())); // do 안쓰고 while부터 쓰면 첫순열을 빼먹어서 모든순열구할떈 do while문 씀,
	// 같은 수가 있어도 잘 돌아감 (ex 1,1,2,2,2)

	return 0;
}
