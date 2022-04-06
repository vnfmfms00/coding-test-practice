#include <string>
#include <vector>
#include <climits>

// 너무 어려워 잘 모르겠음. (풀이 봐도 잘 모르겠음 머리가 안돌아감)
// 나중에 다시 풀어보자

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    vector<int> check(n, 1);
    for (int i = 0; i < weak.size(); i++)
    {
        check[weak[i]] = 0;
    }
    for (int i = dist.size() - 1; i >= 0; i--)
    {
        int a = dist[i];
        int max = INT_MIN;
        for (int j = 0; j < weak.size(); j++)
        {
            int startIdx = weak[j];
            int c = 0;
            // 시계방향, 반시계방향(많은곳)
            for (int k = 0; k < a; k++)
            {
                int b = startIdx + k;
                if (b >= n)
                    b = 0;
                if (check[b] == 0)
                {
                    c++;
                    check[b] = 1;
                }
            }
            if (c > max)
                max = c;
        }


        // 만약 모든 weak를 점검하지 못했다면
        answer++;
        // 점검했다면 return
    }

    return answer;
}