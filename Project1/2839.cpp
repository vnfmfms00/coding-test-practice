#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 0;

	while (true)
	{
		if (n % 5 == 0) // 5�� ������ ���°�?
		{
			result += n / 5;
			break;
		}
		else // 5�� �� ���������� 3�� ���� �ٽ� 5�� ������ ������ �˻� (�̷��� ��� ������ ����..)
		{
			n -= 3;
			result++;
		}

		if (n < 0) // n�� 0���� ������ �ݺ��� Ż��, return -1
		{
			result = -1;
			break;
		}
			
	}

	cout << result << '\n';
}