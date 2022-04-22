#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    long long minValue = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n / i; j >= 1; j--)
        {
            long long r = i;
            long long c = j;

            long long result = a * abs(r - c) + b * (n - r * c); // �ڷ��� ���� �ѳ� ��.


            if (result < minValue)
                minValue = result;
        }
    }

    cout << minValue << '\n';
}