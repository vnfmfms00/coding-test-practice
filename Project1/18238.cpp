#include <iostream>
#include <string>
//#include <cstdlib>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int result = 0;
	int curIdx = 0; // ���ǻ� A�� 0��° �ε��� ��� ����

	for (int i = 0; i < s.length(); i++)
	{
		int nextIdx = s[i] - 'A'; // ���� ������ �ε���
		result += abs(13 - abs(nextIdx - ((curIdx + 13) % 26))); // �ɸ��� �ð� �ּڰ� : abs(13 - abs(���� ������ �ε��� - ���� �ε����� �ݴ뿡 �ش��ϴ� �ε���)) // ���� �ε����� 2�̰� ���� ���� �ε����� 0�ϰ�� 13 -abs()�� ���̳ʽ��� ���� ���� �־ �տ� abs�Լ��� �ѹ� �� ȣ���ؾ���.

		curIdx = nextIdx;
	}

	cout << result << '\n';
}