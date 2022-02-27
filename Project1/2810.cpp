#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cup;
	int coupleCnt = 0;
	int person = s.length();

	int i = 0;
	while (i < s.length())
	{
		if (s[i] == 'L') // Ä¿ÇÃ ÁÂ¼®ÀÏ¶§
		{
			i += 2;
			coupleCnt++;
		}
		else // ÀÏ¹Ý ÁÂ¼®ÀÏ¶§
		{
			i++;
		}
	}

	cup = person - coupleCnt + 1; // ÄÅÈ¦´õ ¼ö: »ç¶÷¼ö - Ä¿ÇÃÁÂ¼®¼ö + 1

	cout << min(cup, person); // ÄÅÈ¦´õ ¼ö¿Í »ç¶÷ ¼ö Áß ÃÖ¼Ú°ªÀÌ ÄÅÈ¦´õ¿¡ ÄÅÀ» ²ÈÀ» ¼ö ÀÖ´Â ÃÖ´ë »ç¶÷ÀÇ ¼ö
}