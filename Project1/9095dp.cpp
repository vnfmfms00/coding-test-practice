#include <iostream>

using namespace std;
int d[11] = { 0 };


int main()
{
	d[0] = 1; // 1,2,3 0개씩 사용하는것 -> 1가지
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i <= 10; i++)
	{
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cout << d[x] << '\n';
	}
}