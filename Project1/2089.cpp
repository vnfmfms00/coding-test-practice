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

		//t�� ����
		//�������� 0
		if ((t % -2) == 0) {
			t = t / -2;
			s = "0" + s;
		}
		//�������� 0�� �ƴѰ�� -> 1�� �����.
		else {
			//t�� ���
			if (t > 0) {
				t = t / -2;
				s = "1" + s;
			}
			//t�� ����
			else {
				//�������� -1�̹Ƿ�
				//�������� 1�� �ǵ��� ��+1
				t = (t / -2) + 1;
				s = "1" + s;

			}
		}
	}
	cout << s << '\n';
}