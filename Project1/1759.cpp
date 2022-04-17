#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int l, c;
	cin >> l >> c;

	vector<char> v(c, 0);
	for (int i = 0; i < c; i++)
	{
		cin >> v[i];
	}

	// 순열 쓰려면 password 오름차순으로 만들어줘야 처음부터 예외없이 돎.
	vector<int> password;
	for (int i = 0; i < c - l; i++)
	{
		password.push_back(0); // 암호에 포함안됨
	}
	for (int i = 0; i < l; i++)
	{
		password.push_back(1); // 암호에 포함됨
	}

	sort(v.begin(), v.end());

	vector<string> vs;
	do
	{
		int m = 0; // 모음개수
		int j = 0; // 자음개수
		string s = "";
		for (int i = 0; i < c; i++)
		{
			if (password[i] == 1)
			{
				s += v[i];
				if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
					m++;
				else
					j++;
			}
		}

		if (m >= 1 && j >= 2)
		{
			vs.push_back(s);
		}

	} while (next_permutation(password.begin(), password.end()));

	sort(vs.begin(), vs.end());

	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << '\n';
	}
}