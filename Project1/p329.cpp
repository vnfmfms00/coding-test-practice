#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이 문제는 못풀었음. 다음에 다시 풀어볼것

// 현재 설치된 구조물이 '가능한' 구조물인지 확인하는 함수
bool possible(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        int x = answer[i][0];
        int y = answer[i][1];
        int a = answer[i][2];
        // 기둥이라면 기둥 조건을 만족하는지 확인
        if (a == 0)
        {
            bool check = false;
            // 바닥 위에 있는가
            if (y == 0)
                check = true;
            for (int j = 0; j < answer.size(); j++)
            {
                // 보의 오른쪽 끝부분 위에 있는가
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;
                
                // 보의 왼쪽 끝부분 위에 있는가
                if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;

                // 또 다른 기둥 위에 있는가
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
            }
            // 안되는 경우라면 false리턴
            if (check == false)
                return false;
        }
        // 보 라면 보 조건을 만족 하는지 확인
        else if (a == 1)
        {
            bool check = false;
            bool left = false;
            bool right = false;
            for (int j = 0; j < answer.size(); j++)
            {
                // 왼쪽 끝부분이 기둥 위에 있는가
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                // 오른쪽 끝부분이 기둥 위에 있는가
                if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                // 양쪽 끝부분이 다른 보와 동시에 연결되어 있는가
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    left = true;
                if (x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    right = true;
            }
            // 양쪽 끝부분이 다른 보와 동시에 연결되어 있다면
            if (left && right)
                check = true;

            if (check == false)
                return false;
        }
    }
    return true; // false한번도 안걸리고 for문 다 돌면 true리턴
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];


        // 삭제라면
        if (b == 0)
        {
            int idx;
            for (int j = 0; j < answer.size(); j++)
            {
                if (x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
                    idx = j;
            }

            vector<int> backup = answer[idx]; // 지워질 벡터 백업
            answer.erase(answer.begin() + idx); // 일단 삭제

            // 나머지가 조건을 만족하지 않으면 복구
            if (possible(answer) == false)
                answer.push_back(backup);
            // 조건을 만족하면 무시

        }
        // 추가 라면
        else if (b == 1)
        {
            vector<int> v = { x, y, a };
            answer.push_back(v); // 일단 추가

            // 조건을 만족하지 않으면 다시 뺌
            if (possible(answer) == false)
                answer.pop_back();
            // 조건을 만족하면 무시
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}