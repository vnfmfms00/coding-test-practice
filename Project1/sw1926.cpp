#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	T = 1;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			string s = to_string(i);
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == '3' || s[j] == '6' || s[j] == '9')
					cnt++;
			}

			if (cnt == 0)
				cout << i << ' ';
			else
			{
				for (int j = 0; j < cnt; j++)
				{
					cout << '-';
				}
				cout << ' ';
			}
		}
		cout << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}