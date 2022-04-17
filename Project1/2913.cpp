#include <iostream>

using namespace std;
int d[91][2];


int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		d[i][1] = d[i - 1][0];
		d[i][0] = d[i - 1][0] + d[i - 1][1];

	}
}