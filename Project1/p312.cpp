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
		//  �� �� �߿� �ϳ��� 0�̳� 1�̸� ������(���� ū ���� ����)
		if (total <= 1 || num <= 1)
			total += (s[i] - '0');
		// �� �� 2 �̻��̶�� ������.
		else
		{
			total *= (s[i] - '0');
		}
				
	}

	cout << total << endl;
	return 0;
}