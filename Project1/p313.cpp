#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int c0 = 0; // ���� 1�� 0���� �ٲ� ī��Ʈ
	int c1 = 0; // ���� 0�� 1�� �ٲ� ī��Ʈ
	int len = str.length();

	if (str[0] == '1')
		c0++;
	else
		c1++;

	for (int i = 0; i < len - 1; i++)
	{
		if (str[i] != str[i + 1])
		{
			// �ڿ� ���� 1�� �ٲ� 1�� 0����
			if (str[i + 1] == '1')
				c0++;
			// �ڿ� ���� 0���� �ٲ� 0�� 1��
			else
				c1++;
		}
	}

	cout << min(c0, c1) << '\n';
}