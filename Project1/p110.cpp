#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n; // 입력 버퍼에 '\n' 문자 남게됨
	cin.ignore(); // 입력버퍼 비워줌

	string s;
	getline(cin, s); // ignore안쓰면 getline이 버퍼에 남아있던 '\n'을 바로읽어 문제발생

	int x = 1;
	int y = 1;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			continue;

		switch (s[i])
		{
		case 'L':
			y--;
			break;
		case 'R':
			y++;
			break;
		case 'U':
			x--;
			break;
		case 'D':
			x++;
			break;
		}

		// x가 범위 벗어났을때 처리
		if (x < 1)
			x = 1;
		else if (x > n)
			x = n;

		// x가 범위 벗어났을때 처리
		if (y < 1)
			y = 1;
		else if (y > n)
			y = n;
	}

	cout << x << ' ' << y << '\n';
}