#include <iostream>
#include <string>
using namespace std;

int d[100001] = { 0 };


//n이 1이 되는 최솟값 구하는 메소드
//d[n]을 구하는 메소드
int getCount(int n) {
	if (n == 1) {
		return 0;
	}
	//메모이제이션
	if (d[n] != 0) return d[n];

	if (true) {
		d[n] = getCount(n - 1) + 1;
	}
	if (n % 2 == 0) {
		int temp = getCount(n / 2) + 1;
		if (d[n] == 0 || temp < d[n]) d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = getCount(n / 3) + 1;
		if (d[n] == 0 || temp < d[n]) d[n] = temp;
	}

	return d[n];
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(nullptr);

	int n;
	cin >> n;
	cout << getCount(n) << '\n';


}
