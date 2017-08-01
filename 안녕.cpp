#include <iostream>
#include <string>
using namespace std;

int Answer;
string str;
int len, HELLO[5];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		cin >> str;
		len = str.length();
		for (int i = 0; i < len; i++) {
			if (str[i] == 'h') HELLO[1]++;
			else if ( str[i] == 'e') HELLO[2]++;
			else if (str[i] == 'l') HELLO[3]++;
			else if (str[i] == 'o') HELLO[4]++;
		}
		while (HELLO[1] >= 1 && HELLO[2] >= 1 && HELLO[3] >= 2 && HELLO[4] >= 1) {
			Answer++;
			HELLO[1]--;
			HELLO[2]--;
			HELLO[3]--; HELLO[3]--;
			HELLO[4]--;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}