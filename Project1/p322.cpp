#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// p.516 ���� ���ڿ��� 0 �� ���ٸ� �̰� Ʋ�� �Լ��ΰŰ���.

int main()
{
	string str;
	cin >> str;

	vector<char> v;
	int total = 0;
	int numCnt = 0; // ���ڿ��� ���Ե� ������ ����

	for (int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c >= 'A' && c <= 'Z')
			v.push_back(c);
		else
		{
			total += (str[i] - '0');
			numCnt++;
		}
			
	}

	// �������� ���� A ~ Z
	sort(v.begin(), v.end());
	
	string s;
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}

	// ���ڰ� ���ڿ��� �ϳ��� ���ԵǾ��ٸ� �� �ڿ� ���ڸ� ���
	if(numCnt != 0)
		s = s + to_string(total);
	
	cout << s;

}