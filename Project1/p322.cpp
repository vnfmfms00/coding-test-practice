#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// p.516 만약 문자열에 0 만 들어갔다면 이건 틀린 함수인거같음.

int main()
{
	string str;
	cin >> str;

	vector<char> v;
	int total = 0;
	int numCnt = 0; // 문자열에 포함된 숫자의 개수

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

	// 오름차순 정렬 A ~ Z
	sort(v.begin(), v.end());
	
	string s;
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}

	// 숫자가 문자열에 하나라도 포함되었다면 맨 뒤에 숫자를 출력
	if(numCnt != 0)
		s = s + to_string(total);
	
	cout << s;

}