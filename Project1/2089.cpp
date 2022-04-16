#include <iostream>

using namespace std;

int main()
{
	int t;
	string s = "";
	cin >> t;

	if (t == 0) {
		cout << '0' << '\n';
		return 0;
	}

	while (true) {
		if (t == 0) {
			break;
		}

		//t를 나눠
		//나머지가 0
		if ((t % -2) == 0) {
			t = t / -2;
			s = "0" + s;
		}
		//나머지가 0이 아닌경우 -> 1로 맞춘다.
		else {
			//t가 양수
			if (t > 0) {
				t = t / -2;
				s = "1" + s;
			}
			//t가 음수
			else {
				//나머지가 -1이므로
				//나머지가 1이 되도록 몫+1
				t = (t / -2) + 1;
				s = "1" + s;

			}
		}
	}
	cout << s << '\n';
}