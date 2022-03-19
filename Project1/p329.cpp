#include <iostream>
#include <vector>

using namespace std;

class RotInfo
{
private :
	int x;
	char c;

public :
	RotInfo(int x, char c)
	{
		this -> x = x;
		this -> c = c;
	}
	int GetX()
	{
		return this -> x;
	}
	char GetC()
	{
		return this -> c;
	}
};

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0)); // n x n ��

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x - 1][y - 1] = 1;
	}

	int l;
	cin >> l;
	vector<RotInfo> v_r; // ���� ��ȯ ���� ����
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		RotInfo rotInfo = { x, c };
		v_r.push_back(rotInfo);
	}

	int time = 0;
	int x = 0, y = 0;
	int dirIdx = 0; // �� ó�� �Ӹ� ���� E
	vector<char> v_dir = { 'E', 'S', 'W', 'N' };
	vector<vector<int>> v_snakeAllPos; // �Ӹ� + ������ ��� ��ġ ����
	vector<int> v_snakeHeadPos = { x, y }; // �ʱ� �Ӹ� ��ġ ó��
	v_snakeAllPos.push_back(v_snakeHeadPos);

	while (true)
	{
		// �ð� 1 ����
		time++;

		// �Ӹ� ���⿡ ���� 1ĭ �̵�(������ �տ��ִ� �����̳� �Ӹ� ����), ���� �ø�
		switch (v_dir[dirIdx])
		{
		case 'E':
			y++;
			break;
		case 'S':
			x++;
			break;
		case 'W':
			y--;
			break;
		case 'N':
			x--;
			break;
		}

		// ���� �Ӹ����� �������� �߰�
		v_snakeHeadPos = { x, y }; // ���ο� �Ӹ� ��ġ
		vector<vector<int>>::iterator it = v_snakeAllPos.begin();
		v_snakeAllPos.insert(it, v_snakeHeadPos); // ���ο� �Ӹ� ��ġ�� �� �տ� �߰�

		// ���� �Ӹ��� ���� �ھ����� ���� ���ӳ� time ����
		if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
		{
			cout << time << '\n';
			return 0;
		}
		// ���� �Ӹ��� ������ �ھ����� ���� ���ӳ� time ����
		for (int i = 1; i < v_snakeAllPos.size(); i++)
		{
			if (x == v_snakeAllPos[i][0] && y == v_snakeAllPos[i][1])
			{
				cout << time << '\n';
				return 0;
			}
		}
		
		// ���׾��ٸ� ��� �Ծ����� üũ
		// ��� �Ծ��ٸ� �״��, �ƴϸ� ���� ���
		// �Ӹ��� ��ġ�� ����� ��ġ�� ������ ������
		if (v[x][y] == 1)
		{
			v[x][y] = 0; // ��� ����
		}
		// ��� �ȸԾ����� ���� ���
		else
		{
			v_snakeAllPos.pop_back();
		}

		// �ش��ϴ� �ʰ� �Ǿ����� �Ӹ� ���� �ٲ�
		for (int i = 0; i < v_r.size(); i++)
		{
			if (time == v_r[i].GetX())
			{
				// �������� ȸ��
				if (v_r[i].GetC() == 'L')
				{
					dirIdx--;
					if (dirIdx < 0)
						dirIdx = v_dir.size() - 1;
				}
				// ���������� ȸ��
				else
				{
					dirIdx++;
					if (dirIdx > v_dir.size() - 1)
						dirIdx = 0;
				}
			}
		}
	}
}
