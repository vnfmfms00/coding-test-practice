#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	//cin >> T;
	T = 1;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				v[i][j] = s[j] -'0'; // string���� �����Ÿ� �̷��� �޾Ƶ� ��.
				// cin >> v[i][j]; ��� �ϳ��� �Է� �ȹ޾��� char�� �Ǵ���
				
				//scanf("%1d", &v[i][j]); // int map�� �̷��� �޾ƾ� ��.
				//cout << "aaaa" << v[i][j] << '\n';
			}
		}

		int result = 0;
		int temp;
		for (int i = 0; i < n; i++)
		{
			temp = abs(i - n / 2);
			for (int j = 0; j < n; j++)
			{
				if (j >= temp && j <= n - 1 - temp)
				{
					result += v[i][j];
				}
			}
		}

		cout << "#" << test_case << ' ' << result << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}