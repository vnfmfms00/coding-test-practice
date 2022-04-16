#include <iostream>
#include <vector>

using namespace std;

// i 에서 출발해서 i로 끝나나?
bool IsComplete(vector<vector<int>> _map)
{
	bool isComplete = true;
	// i는 열
	for (int i = 0; i < h; i++)
	{
		int startIdx = i;

		// j는 행
		for (int j = 0; j < n; j++)
		{
			// 가로선 만나면 옆으로 새고 한줄 내려가
			if (_map[j][startIdx] == 1)
			{
				// 왼쪽 가로선
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
				
				// 오른쪽 가로선
				else
				{

				}
			}
			// 안만나면 그냥 한줄 내려가
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
		
		// 먼저 확인하고
		if (IsComplete(map) == true)
		{
			break;
		}
		else
		{
			// 가로선을 더 넣을 수 있는가?

			// 더 못넣으면 return -1

			// 넣을 수 있으면 result +1
			// 맵 바꿔
		}
		
		


		

	}
	
	cout << result << '\n';
}