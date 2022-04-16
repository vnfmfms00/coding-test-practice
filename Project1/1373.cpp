#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int len = s.length();
	int cnt = 0;
	int result = 0;
	if (len % 3 == 0)
	{

	}
	else if (len % 3 == 1)
	{
		s = "00" + s;
	}
	else if (len % 3 == 2)
	{
		s = "0" + s;
	}
	len = s.length();
	
	for (int i = 0; i < len; i++)
	{
		if (cnt == 0)
			result += 4 * (s[i] - '0');
		else if (cnt == 1)
			result += 2 * (s[i] - '0');
		else if (cnt == 2)
			result += (s[i] - '0');

		cnt++;
		if (cnt >= 3)
		{
			cout << result;
			result = 0;
			cnt = 0;
		}
	}
	cout << '\n';

	cout << -13 % -2 << -13 / -2 << '\n';
}