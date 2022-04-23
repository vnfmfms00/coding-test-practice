#include<iostream>
#include<string>
using namespace std;

string GetBinaryCode(char c) // 문자를 6자리 이진수로 변환
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

char GetCharacter(string s) // 8진수를 숫자로 변환
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
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
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
             이 부분에 여러분의 알고리즘 구현이 들어갑니다.
         */
         /////////////////////////////////////////////////////////////////////////////////////////////


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}