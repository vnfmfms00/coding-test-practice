#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[4] = { 25, 10, 5, 1 };
	int len = sizeof arr / sizeof arr[0];

	int n;
	cin >> n;

	vector<int> v;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n; i++)
	{
		int idx = 0;
		vector<int> v1(4, 0);

		while(true)
		{
			// �Ž������� ���� ���ϰ��ִ� �� �������� ũ�� ���� ���� ����
			if (v[i] >= arr[idx])
			{
				v1[idx] = (v[i] / arr[idx]); // �� ����
				v[i] %= arr[idx]; // �������� �Ž��������� ����
			}
				
			else // ������ ���� �� ������ ��
				idx++;

			if (idx >= len) // �� ��
				break;
		}

		// ���
		for (int j = 0; j < v1.size(); j++)
		{
			cout << v1[j] << ' ';
		}
		cout << '\n';
	}
	
}