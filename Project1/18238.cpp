#include <iostream>
#include <string>
//#include <cstdlib>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int result = 0;
	int curIdx = 0; // 편의상 A는 0번째 인덱스 라고 정함

	for (int i = 0; i < s.length(); i++)
	{
		int nextIdx = s[i] - 'A'; // 다음 문자의 인덱스
		result += abs(13 - abs(nextIdx - ((curIdx + 13) % 26))); // 걸리는 시간 최솟값 : abs(13 - abs(다음 문자의 인덱스 - 현재 인덱스의 반대에 해당하는 인덱스)) // 현재 인덱스가 2이고 다음 문자 인덱스가 0일경우 13 -abs()가 마이너스가 나올 수도 있어서 앞에 abs함수를 한번 더 호출해야함.

		curIdx = nextIdx;
	}

	cout << result << '\n';
}