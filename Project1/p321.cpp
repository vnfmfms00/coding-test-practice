#include <iostream>
#include <string>


using namespace std;

int main()
{
	int n;
	cin >> n;

	string s = to_string(n);
	int len = s.length();

	int left = 0, right = 0;
	for (int i = 0; i < len; i++)
	{
		if (i < len / 2)
			left += (s[i] - '0');
		else
			right += (s[i] - '0');
	}

	if (left == right)
		cout << "LUCKY" << '\n';
	else
		cout << "READY" << '\n';
}