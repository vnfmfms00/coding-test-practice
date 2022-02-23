#include <iostream>
#include <string>

using namespace std;

int FiveToSix(string s);
int SixToFive(string s);

int main()
{
	int a, b, min, max;
	cin >> a >> b;

	string s1 = to_string(a);
	string s2 = to_string(b);

	min = SixToFive(s1) + SixToFive(s2);
	max = FiveToSix(s1) + FiveToSix(s2);

	cout << min << ' ' <<  max << '\n';
}

// 5�� ��� 6����
int FiveToSix(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '5')
			s[i] = '6';
	}

	return stoi(s);
}

// 6�� ��� 5��
int SixToFive(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '6')
			s[i] = '5';
	}

	return stoi(s);
}