#include <iostream>
#include <vector>


using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(11, 0); // 11���� ���� 0���� �ʱ�ȭ. ���Կ� ���� ������ ���� ����

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x]++;
	}

	int result = 0;
	for (int i = 1; i <= m; i++)
	{
		n -= v[i]; // a�� ���� i �� �������� �����Ҷ�, b�� �����ϴ� ����� ��
		result += v[i] * n; // a�� ���� i�� ���� �����Ҷ� ����� ��(v[i]) * b�� �����ϴ� ����� ��(n)
	}

	cout << result << '\n';
}