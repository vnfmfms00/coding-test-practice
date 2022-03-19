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

	vector<vector<int>> v(n, vector<int>(n, 0)); // n x n 맵

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
	vector<RotInfo> v_r; // 방향 전환 정보 저장
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
	int dirIdx = 0; // 맨 처음 머리 방향 E
	vector<char> v_dir = { 'E', 'S', 'W', 'N' };
	vector<vector<int>> v_snakeAllPos; // 머리 + 몸통의 모든 위치 저장
	vector<int> v_snakeHeadPos = { x, y }; // 초기 머리 위치 처장
	v_snakeAllPos.push_back(v_snakeHeadPos);

	while (true)
	{
		// 시간 1 증가
		time++;

		// 머리 방향에 따라 1칸 이동(몸통은 앞에있는 몸통이나 머리 따라감), 몸통 늘림
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

		// 기존 머리분을 몸통으로 추가
		v_snakeHeadPos = { x, y }; // 새로운 머리 위치
		vector<vector<int>>::iterator it = v_snakeAllPos.begin();
		v_snakeAllPos.insert(it, v_snakeHeadPos); // 새로운 머리 위치를 맨 앞에 추가

		// 만약 머리가 벽에 박았으면 죽음 게임끝 time 리턴
		if (x < 0 || x > n - 1 || y < 0 || y > n - 1)
		{
			cout << time << '\n';
			return 0;
		}
		// 만약 머리가 꼬리에 박았으면 죽음 게임끝 time 리턴
		for (int i = 1; i < v_snakeAllPos.size(); i++)
		{
			if (x == v_snakeAllPos[i][0] && y == v_snakeAllPos[i][1])
			{
				cout << time << '\n';
				return 0;
			}
		}
		
		// 안죽었다면 사과 먹었는지 체크
		// 사과 먹었다면 그대로, 아니면 몸통 축소
		// 머리의 위치와 사과의 위치가 같으면 먹은거
		if (v[x][y] == 1)
		{
			v[x][y] = 0; // 사과 없앰
		}
		// 사과 안먹었으면 몸통 축소
		else
		{
			v_snakeAllPos.pop_back();
		}

		// 해당하는 초가 되었으면 머리 방향 바꿈
		for (int i = 0; i < v_r.size(); i++)
		{
			if (time == v_r[i].GetX())
			{
				// 왼쪽으로 회전
				if (v_r[i].GetC() == 'L')
				{
					dirIdx--;
					if (dirIdx < 0)
						dirIdx = v_dir.size() - 1;
				}
				// 오른쪽으로 회전
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
