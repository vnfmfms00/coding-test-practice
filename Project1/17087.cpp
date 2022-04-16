#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(abs(x - s)); // 수빈과 동생사이의 거리 저장
	}
	
	int result = v[0];
		
	for (int i = 1; i < n; i++)
	{
		result = gcd(result, v[i]);
	}
	
	cout << result << '\n';

}