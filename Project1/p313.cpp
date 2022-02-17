#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int c0 = 0; // 전부 1이 0으로 바뀔때 카운트
	int c1 = 0; // 전부 0이 1로 바뀔때 카운트
	int len = str.length();

	if (str[0] == '1')
		c0++;
	else
		c1++;

	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] != str[i + 1])
		{
			// 뒤에 수가 1로 바뀔때 1을 0으로
			if (str[i + 1] == '1')
				c0++;
			// 뒤에 수가 0으로 바뀔때 0을 1로
			else
				c1++;
		}
	}

	cout << min(c0, c1) << '\n';
}