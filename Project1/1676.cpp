#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int result = 0;
	for (int i = 5; i <= n; i = i * 5)
	{
		result += n / i;
	}

	cout << result << '\n';
}