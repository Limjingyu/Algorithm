#include <iostream>

using namespace std;

unsigned int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;

		unsigned int input = 0;
		Answer = 0;
		for (int i = 0; i<N; i++) {
			cin >> input;
			Answer ^= input;
		}


		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}