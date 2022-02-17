#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int len = s.length();
	int total = s[0] - '0';
	for (int i = 1; i < len; i++)
	{
		int num = s[i] - '0';
		//  두 수 중에 하나라도 0이나 1이면 더해줌(가장 큰 값을 위해)
		if (total <= 1 || num <= 1)
			total += (s[i] - '0');
		// 둘 다 2 이상이라면 곱해줌.
		else
		{
			total *= (s[i] - '0');
		}
				
	}

	cout << total << endl;
	return 0;
}