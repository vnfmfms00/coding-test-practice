#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cup;
	int coupleCnt = 0;
	int person = s.length();

	int i = 0;
	while (i < s.length())
	{
		if (s[i] == 'L') // Ŀ�� �¼��϶�
		{
			i += 2;
			coupleCnt++;
		}
		else // �Ϲ� �¼��϶�
		{
			i++;
		}
	}

	cup = person - coupleCnt + 1; // ��Ȧ�� ��: ����� - Ŀ���¼��� + 1

	cout << min(cup, person); // ��Ȧ�� ���� ��� �� �� �ּڰ��� ��Ȧ���� ���� ���� �� �ִ� �ִ� ����� ��
}