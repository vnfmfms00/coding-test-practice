#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 올바른 괄호 문자열인지 체크
bool check(string s)
{
    int cnt_left = 0;
    int cnt_right = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            cnt_left++;
        else
            cnt_right++;

        if (cnt_left - cnt_right < 0)
            return false;
    }
    return true;
}

string func(string s)
{
    // 1
    if (s == "")
        return s;

    // 2
    // u, v 로 분리
    string u = "";
    string v = "";
    int cnt_left = 0;
    int cnt_right = 0;
    int idx = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            cnt_left++;
        else
            cnt_right++;

        // 가장 짧은 균형잡힌 괄호문자열
        if ((cnt_left >= 1 || cnt_right >= 1) && cnt_left - cnt_right == 0)
        {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (i <= idx)
            u += s[i];
        else
            v += s[i];
    }

    if (check(u))
        return u + func(v);
    else
    {
        string temp = "";
        temp += '(';
        temp += func(v);
        temp += ')';
        // 
        if (u.length() > 2)
        {
            for (int i = 1; i < u.length() - 1; i++)
            {
                if (u[i] == '(')
                    temp += ')';
                else
                    temp += '(';
            }
        }

        return temp;
    }
}

string solution(string p) {
    string answer = "";
    answer = func(p);
    
    return answer;
}

int main()
{
    string p;
    cin >> p;
    cout << solution(p) << '\n';
}
