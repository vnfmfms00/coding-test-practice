#include <iostream>
#include <string>

using namespace std;

int main()
{
	string pos;
	cin >> pos;

	int x = pos[0] - 'a' + 1; // 1~8
	int y = pos[1] - '0'; // 1~8

	int arr[8][2] = { {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1} };

	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		if ((x + arr[i][0]) > 8 || (x + arr[i][0]) < 1 || (y + arr[i][1]) > 8 || (y + arr[i][1]) < 1)
			continue;
		
		cnt++;
	}

	cout << cnt << '\n';
}