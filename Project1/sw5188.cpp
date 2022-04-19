#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int min1 = INT_MAX;
void go(int row, int col, vector<vector<int>> &a, int cost)
{
	if (row == n - 1 && col == n - 1)
	{
		if (min1 > cost)
		{
			min1 = cost;
			return;
		}
	}

	if (row + 1 < n)
		go(row + 1, col, a, cost + a[row + 1][col]);
	if (col + 1 < n)
		go(row, col + 1, a, cost + a[row][col + 1]);
}

// 얘는 왜 안되는지 모르겠음. 끝났을때만 리턴해야하나?
//int go(int row, int col, vector<vector<int>>& a, int cost)
//{
//	if (row == n - 1 && col == n - 1)
//	{
//		if (min1 > cost)
//		{
//			min1 = cost;
//			return min1;
//		}
//	}
//
//	if (row + 1 < n)
//		return go(row + 1, col, a, cost + a[row + 1][col]);
//	if (col + 1 < n)
//		return go(row, col + 1, a, cost + a[row][col + 1]);
//}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v[i][j];
			}
		}
		go(0, 0, v, v[0][0]);
		cout << "#" << test_case << ' ' << min1 << '\n';
		min1 = INT_MAX;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}