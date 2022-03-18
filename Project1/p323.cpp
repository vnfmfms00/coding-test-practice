#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int unit = 1;
    answer = s.length();
    while (true)
    {
        if (unit > s.length() / 2)
            break;
        
        string s1 = "";
        string s3 = "";
        int cnt = 1;
        for (int i = 0; i < s.length();)
        {
            if (i == 0)
            {
                for (int j = 0; j < unit; j++)
                {
                    // unit������ ��Ȯ�� �ȳ���������� index��������°�찡 �־ ������.
                    if(j + i < s.length())
                        s1 += s[j + i];
                }
            }
            else
            {
                string s2 = "";
                for (int j = 0; j < unit; j++)
                {
                    if (j + i < s.length())
                        s2 += s[j + i];
                }

                if (s1 == s2)
                {
                    cnt++;
                }
                else
                {
                    // �ٸ��� �տ��� ���ڿ� s3�� �߰�
                    if (cnt == 1)
                    {
                        s3 += s1;
                    }
                    else
                    {
                        s3 += (to_string(cnt) + s1);
                    }
                    cnt = 1;
                    s1 = s2;
                }
            }
            i += unit;
        }

        // ������ s3���ڿ��� ���� ���ڿ��� �־������.
        if (cnt == 1)
            s3 += s1;
        else
            s3 += (to_string(cnt) + s1);

        if (s3.length() < answer)
            answer = s3.length();

        unit++;

        cout << s3 << '\n';
    }
    return answer;
}

int main()
{
    string str;
    cin >> str;

    cout << solution(str) << '\n';
}