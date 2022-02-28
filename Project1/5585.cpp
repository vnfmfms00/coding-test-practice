#include <iostream>

using namespace std;

int main()
{
	int arr[6] = { 500, 100, 50, 10, 5, 1 };
	int n;
	cin >> n;

	int money = 1000 - n; // ¹ŞÀ» ÀÜµ·
	int cnt = 0; // ÀÜµ·ÀÇ °³¼ö

	for (int i = 0; i < 6; i++)
	{
		// °Å½½·¯ Áà¾ß ÇÒ µ·ÀÌ ÀÜµ· ´ÜÀ§º¸´Ù Å©°Å³ª °°À¸¸é ÀÜµ· °³¼ö Ãß°¡
		if (arr[i] <= money)
		{
			cnt += (money / arr[i]);
			money %= arr[i];
		}
	}

	cout << cnt << '\n';
}