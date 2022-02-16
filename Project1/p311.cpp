#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}


	sort(v.begin(), v.end()); // ��������

	int result = 0; // �� �׷� ��
	int count = 0; // ���� �׷쿡 ���� ���谡 ��

	for (int i = 0; i < n; i++)
	{
		count += 1; // �ϴ� ���� �׷쿡 �ο� �߰�
		if (count >= v[i]) // ���� �׷� �ο��� ������ ���������� ���ų� ������ �׷� �Ἲ �Ϸ�
		{
			result += 1; // �� �׷� �� ����
			count = 0; // ���� �׷� �ʱ�ȭ
		}
	}

	cout << result << endl;
	return 0;
}