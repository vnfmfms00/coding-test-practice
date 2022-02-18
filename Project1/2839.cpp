#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int result = 0;

	while (true)
	{
		if (n % 5 == 0) // 5로 나누어 지는가?
		{
			result += n / 5;
			break;
		}
		else // 5로 안 나누어지면 3을 뺀후 다시 5로 나누어 지는지 검사 (이런걸 어떻게 생각해 내냐..)
		{
			n -= 3;
			result++;
		}

		if (n < 0) // n이 0보다 작으면 반복문 탈출, return -1
		{
			result = -1;
			break;
		}
			
	}

	cout << result << '\n';
}