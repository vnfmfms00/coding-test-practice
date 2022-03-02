#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n; // �Է� ���ۿ� '\n' ���� ���Ե�
	cin.ignore(); // �Է¹��� �����

	string s;
	getline(cin, s); // ignore�Ⱦ��� getline�� ���ۿ� �����ִ� '\n'�� �ٷ��о� �����߻�

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

		// x�� ���� ������� ó��
		if (x < 1)
			x = 1;
		else if (x > n)
			x = n;

		// x�� ���� ������� ó��
		if (y < 1)
			y = 1;
		else if (y > n)
			y = n;
	}

	cout << x << ' ' << y << '\n';
}