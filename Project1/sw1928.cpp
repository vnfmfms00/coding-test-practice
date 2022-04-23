#include<iostream>
#include<string>
using namespace std;

string GetBinaryCode(char c) // ���ڸ� 6�ڸ� �������� ��ȯ
{
    string s = "";
    int num = -1;
    if (c >= 'A' && c <= 'Z')
        num = c - 'A';
    else if (c >= 'a' && c <= 'z')
        num = c - 'a' + 26;
    else if (c >= '0' && c <= '9')
        num = c - '0' + 52;
    else if (c == '+')
        num = 62;
    else if (c == '/')
        num = 63;

    while (num > 0)
    {
        s = to_string(num % 2) + s;
        num /= 2;
    }
    int len = s.length();
    for (int i = len; i < 6; i++)
    {
        s = '0' + s;
    }
    return s;
}

char GetCharacter(string s) // 8������ ���ڷ� ��ȯ
{
    char c;
    int len = s.length();
    int result = 0;
    int temp = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        result += (s[i] - '0') * temp;
        temp *= 2;
    }
    c = result;
    return c;
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
        string s;
        cin >> s;
        int len = s.length();
        string newString = "";
        for (int i = 0; i < len; i++)
        {
            newString = newString + GetBinaryCode(s[i]);
        }
        int newLen = newString.length();
        string answer = "";
        for (int i = 0; i < newLen; i = i + 8)
        {
            string binaryString = "";
            for (int j = i; j < i + 8; j++)
            {
                binaryString += newString[j];
            }
            answer += GetCharacter(binaryString);
        }

        cout << "#" << test_case << ' ' << answer << '\n';
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
             �� �κп� �������� �˰��� ������ ���ϴ�.
         */
         /////////////////////////////////////////////////////////////////////////////////////////////


    }
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}