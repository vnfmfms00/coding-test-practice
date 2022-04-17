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

	// ���� ������ password ������������ �������� ó������ ���ܾ��� ��.
	vector<int> password;
	for (int i = 0; i < c - l; i++)
	{
		password.push_back(0); // ��ȣ�� ���Ծȵ�
	}
	for (int i = 0; i < l; i++)
	{
		password.push_back(1); // ��ȣ�� ���Ե�
	}

	sort(v.begin(), v.end());

	vector<string> vs;
	do
	{
		int m = 0; // ��������
		int j = 0; // ��������
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