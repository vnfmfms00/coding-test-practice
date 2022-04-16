#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int x;
		cin >> x;
		int cnt = 0;
		for (int i1 = 1; i1 <= 3; i1++)
		{
			if (x == i1) cnt++;
			for (int i2 = 1; i2 <= 3; i2++)
			{
				if (x == i1 + i2) cnt++;
				for (int i3 = 1; i3 <= 3; i3++)
				{
					if (x == i1 + i2 + i3) cnt++;
					for (int i4 = 1; i4 <= 3; i4++)
					{
						if (x == i1 + i2 + i3 + i4) cnt++;
						for (int i5 = 1; i5 <= 3; i5++)
						{
							if (x == i1 + i2 + i3 + i4 + i5) cnt++;
							for (int i6 = 1; i6 <= 3; i6++)
							{
								if (x == i1 + i2 + i3 + i4 + i5 + i6) cnt++;
								for (int i7 = 1; i7 <= 3; i7++)
								{
									if (x == i1 + i2 + i3 + i4 + i5 + i6 + i7) cnt++;
									for (int i8 = 1; i8 <= 3; i8++)
									{
										if (x == i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8) cnt++;
										for (int i9 = 1; i9 <= 3; i9++)
										{
											if (x == i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9) cnt++;
											for (int i10 = 1; i10 <= 3; i10++)
											{
												if (x == i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10) cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		cout << cnt << '\n';
	}
}