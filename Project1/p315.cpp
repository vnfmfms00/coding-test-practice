#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(11, 0); // 11개의 원소 0으로 초기화. 무게에 따른 볼링공 개수 저장

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x]++;
	}

	int result = 0;
	for (int i = 1; i <= m; i++)
	{
		n -= v[i]; // a가 무게 i 인 볼링공을 선택할때, b가 선택하는 경우의 수
		result += v[i] * n; // a가 무게 i인 공을 선택할때 경우의 수(v[i]) * b가 선택하는 경우의 수(n)
	}

	cout << result << '\n';
}