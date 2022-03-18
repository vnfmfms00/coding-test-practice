#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> _v)
{
    int row = _v.size();
    int col = _v[0].size();
    vector<vector<int>> v1(row, vector<int>(col, 0));

    
    // �ð���� 90�� ȸ���Ͽ� v1�� ����
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

    // ����key, 90�� ȸ��, 180�� ȸ��, 270�� ȸ�� �� key ��������.
    vector<vector<vector<int>>> vv;
    vector<vector<int>> key90 = rotate90(key);
    vector<vector<int>> key180 = rotate90(key90);
    vector<vector<int>> key270 = rotate90(key180);
    vv.push_back(key);
    vv.push_back(key90);
    vv.push_back(key180);
    vv.push_back(key270);

    // ���ο� 2���� vector ����(lock�� �𼭸����� key�� ����� ���� ������ ��� ����)
    int row = lock.size() + (key.size() - 1) * 2;
    int col = lock[0].size() + (key[0].size() - 1) * 2;
    vector<vector<int>> v(row, vector<int>(col, -1));

    int lockHole = 0; // �ڹ��� ���豸�� ����
    for (int i = 0; i < lock.size(); i++)
    {
        for (int j = 0; j < lock[0].size(); j++)
        {
            // lock Ȩ
            if (lock[i][j] == 0)
            {
                v[i + key.size() - 1][j + key[0].size() - 1] = 0;
                lockHole++;
            }
            // lock ����
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
            // ����, 90�� ȸ��, 180�� ȸ��, 270�� ȸ�� ��
            for (int x = 0; x < 4; x++)
            {
                int cnt = 0;
                bool canBeAnswer = true;
                for (int k = 0; k < key.size(); k++)
                {
                    for (int m = 0; m < key[0].size(); m++)
                    {
                        // key ����� lock ���Ⱑ �¹����� ������ �� �� ����
                        if (vv[x][k][m] == 1 && v[i + k][j + m] == 1)
                            canBeAnswer = false;
                        else if (vv[x][k][m] == 1 && v[i + k][j + m] == 0)
                            cnt++;
                    }
                }

                // ������ �� �� ���� ���¸� �ѱ�
                if (canBeAnswer == false)
                    continue;

                // ������ �� �� �ִ� ���¸�
                // ���赹�Ⱑ �ڹ���Ȩ�� ��ġ�ϴ� ������ �ڹ��� ���豸���� ������
                // ��ġ�ϸ� ����
                if (cnt == lockHole)
                {
                    answer = true;
                    return answer;
                }
                // �ƴϸ� ������ ��
            }
            
        }
    }

    // ���� ������ false��ȯ
    return answer;
}

int main()
{
    
}