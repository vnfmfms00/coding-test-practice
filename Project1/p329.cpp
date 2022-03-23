#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �� ������ ��Ǯ����. ������ �ٽ� Ǯ���

// ���� ��ġ�� �������� '������' ���������� Ȯ���ϴ� �Լ�
bool possible(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        int x = answer[i][0];
        int y = answer[i][1];
        int a = answer[i][2];
        // ����̶�� ��� ������ �����ϴ��� Ȯ��
        if (a == 0)
        {
            bool check = false;
            // �ٴ� ���� �ִ°�
            if (y == 0)
                check = true;
            for (int j = 0; j < answer.size(); j++)
            {
                // ���� ������ ���κ� ���� �ִ°�
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;
                
                // ���� ���� ���κ� ���� �ִ°�
                if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    check = true;

                // �� �ٸ� ��� ���� �ִ°�
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
            }
            // �ȵǴ� ����� false����
            if (check == false)
                return false;
        }
        // �� ��� �� ������ ���� �ϴ��� Ȯ��
        else if (a == 1)
        {
            bool check = false;
            bool left = false;
            bool right = false;
            for (int j = 0; j < answer.size(); j++)
            {
                // ���� ���κ��� ��� ���� �ִ°�
                if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                // ������ ���κ��� ��� ���� �ִ°�
                if (x + 1 == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2])
                    check = true;
                // ���� ���κ��� �ٸ� ���� ���ÿ� ����Ǿ� �ִ°�
                if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    left = true;
                if (x + 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2])
                    right = true;
            }
            // ���� ���κ��� �ٸ� ���� ���ÿ� ����Ǿ� �ִٸ�
            if (left && right)
                check = true;

            if (check == false)
                return false;
        }
    }
    return true; // false�ѹ��� �Ȱɸ��� for�� �� ���� true����
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];


        // �������
        if (b == 0)
        {
            int idx;
            for (int j = 0; j < answer.size(); j++)
            {
                if (x == answer[j][0] && y == answer[j][1] && a == answer[j][2])
                    idx = j;
            }

            vector<int> backup = answer[idx]; // ������ ���� ���
            answer.erase(answer.begin() + idx); // �ϴ� ����

            // �������� ������ �������� ������ ����
            if (possible(answer) == false)
                answer.push_back(backup);
            // ������ �����ϸ� ����

        }
        // �߰� ���
        else if (b == 1)
        {
            vector<int> v = { x, y, a };
            answer.push_back(v); // �ϴ� �߰�

            // ������ �������� ������ �ٽ� ��
            if (possible(answer) == false)
                answer.pop_back();
            // ������ �����ϸ� ����
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}