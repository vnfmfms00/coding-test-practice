#include <iostream>
#include <vector>

using namespace std;

// i ���� ����ؼ� i�� ������?
bool IsComplete(vector<vector<int>> _map)
{
	bool isComplete = true;
	// i�� ��
	for (int i = 0; i < h; i++)
	{
		int startIdx = i;

		// j�� ��
		for (int j = 0; j < n; j++)
		{
			// ���μ� ������ ������ ���� ���� ������
			if (_map[j][startIdx] == 1)
			{
				// ���� ���μ�
				if (startIdx >= 1)
				{
					if (_map[j][startIdx - 1] == 1)
					{
						startIdx--;
					}
					else if (_map[j][startIdx + 1] == 1)
					{
						startIdx++;
					}
				}
				
				// ������ ���μ�
				else
				{

				}
			}
			// �ȸ����� �׳� ���� ������
		}

		if (startIdx != i)
		{
			isComplete = false;
			break;
		}
	}
	return isComplete;
}

bool CanPut(vector<vector<int>> _map)
{
	bool canPut = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if(_map[i][j] == 0 && _map)
		}
	}
}

int n, m, h;

int main()
{
	
	cin >> n >> m >> h;

	vector<vector<int>> map(h, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = 1;
	}

	int result = 0;
	while (true)
	{
		if (result > 3)
		{
			result = -1;
			break;
		}
		
		// ���� Ȯ���ϰ�
		if (IsComplete(map) == true)
		{
			break;
		}
		else
		{
			// ���μ��� �� ���� �� �ִ°�?

			// �� �������� return -1

			// ���� �� ������ result +1
			// �� �ٲ�
		}
		
		


		

	}
	
	cout << result << '\n';
}