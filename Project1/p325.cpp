#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> _v)
{
    int row = _v.size();
    int col = _v[0].size();
    vector<vector<int>> v1(row, vector<int>(col, 0));

    
    // 시계방향 90도 회전하여 v1에 저장
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            v1[j][col - 1 - i] = _v[i][j];
        }
    }

    return v1;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    // 원본key, 90도 회전, 180도 회전, 270도 회전 한 key 만들어야함.
    vector<vector<vector<int>>> vv;
    vector<vector<int>> key90 = rotate90(key);
    vector<vector<int>> key180 = rotate90(key90);
    vector<vector<int>> key270 = rotate90(key180);
    vv.push_back(key);
    vv.push_back(key90);
    vv.push_back(key180);
    vv.push_back(key270);

    // 새로운 2차원 vector 생성(lock의 모서리부터 key를 대봤을 때의 공간을 모두 포함)
    int row = lock.size() + (key.size() - 1) * 2;
    int col = lock[0].size() + (key[0].size() - 1) * 2;
    vector<vector<int>> v(row, vector<int>(col, -1));

    int lockHole = 0; // 자물쇠 열쇠구멍 개수
    for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock[0].size(); j++)
        {
            // lock 홈
            if (lock[i][j] == 0)
            {
                v[i + key.size() - 1][j + key[0].size() - 1] = 0;
                lockHole++;
            }
            // lock 돌기
            else
            {
                v[i + key.size() - 1][j + key[0].size() - 1] = 1;
            }
        }
    }

    for (int i = 0; i < row - (key.size() - 1); i++)
    {
        for (int j = 0; j < col - (key[0].size() - 1); j++)
        {
            // 원본, 90도 회전, 180도 회전, 270도 회전 비교
            for (int x = 0; x < 4; x++)
            {
                int cnt = 0;
                bool canBeAnswer = true;
                for (int k = 0; k < key.size(); k++)
                {
                    for (int m = 0; m < key[0].size(); m++)
                    {
                        // key 돌기와 lock 돌기가 맞물리면 정답이 될 수 없음
                        if (vv[x][k][m] == 1 && v[i + k][j + m] == 1)
                            canBeAnswer = false;
                        else if (vv[x][k][m] == 1 && v[i + k][j + m] == 0)
                            cnt++;
                    }
                }

                // 정답이 될 수 없는 상태면 넘김
                if (canBeAnswer == false)
                    continue;

                // 정답이 될 수 있는 상태면
                // 열쇠돌기가 자물쇠홈에 일치하는 개수와 자물쇠 열쇠구멍의 개수비교
                // 일치하면 정답
                if (cnt == lockHole)
                {
                    answer = true;
                    return answer;
                }
                // 아니면 다음거 비교
            }
            
        }
    }

    // 정답 없을때 false반환
    return answer;
}

int main()
{
    
}