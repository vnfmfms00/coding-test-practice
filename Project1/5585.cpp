#include <iostream>

using namespace std;

int main()
{
	int arr[6] = { 500, 100, 50, 10, 5, 1 };
	int n;
	cin >> n;

	int money = 1000 - n; // ���� �ܵ�
	int cnt = 0; // �ܵ��� ����

	for (int i = 0; i < 6; i++)
	{
		// �Ž��� ��� �� ���� �ܵ� �������� ũ�ų� ������ �ܵ� ���� �߰�
		if (arr[i] <= money)
		{
			cnt += (money / arr[i]);
			money %= arr[i];
		}
	}

	cout << cnt << '\n';
}