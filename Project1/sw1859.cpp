#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

long long GetMax(int startIdx, vector<long long>& a)
{
	long long max = 0;
	for (int i = startIdx; i < a.size(); i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

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
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; // n�� �ִ� �鸸
		cin >> n;
		vector<long long> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		long long max = 0;
		int buyCnt = 0;
		long long buyCost = 0;
		long long profit = 0;
		max = GetMax(0, v);
		for (int i = 0; i < n; i++)
		{
			// buy
			if (v[i] < max)
			{
				buyCnt++;
				buyCost += v[i];
			}
			// sell
			else
			{
				profit += max * buyCnt - buyCost;
				max = GetMax(i + 1, v); // max�� ����
				buyCnt = 0;
				buyCost = 0;
			}
		}

		cout << "#" << test_case << ' ' << profit << '\n';

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}