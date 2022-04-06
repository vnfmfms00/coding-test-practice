#include <string>
#include <vector>
#include <climits>

// �ʹ� ����� �� �𸣰���. (Ǯ�� ���� �� �𸣰��� �Ӹ��� �ȵ��ư�)
// ���߿� �ٽ� Ǯ���

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
            // �ð����, �ݽð����(������)
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


        // ���� ��� weak�� �������� ���ߴٸ�
        answer++;
        // �����ߴٸ� return
    }

    return answer;
}