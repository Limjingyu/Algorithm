#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;

		int a, b;
		int NN;
		int flag = 0;
		for (Answer = 2; Answer*Answer < N; Answer++) {
			NN = N;
			while (1) {
				a = NN % Answer;
				NN /= Answer;
				if (NN < Answer) {
					if(NN == a) { flag = 1; break; }
					break;
				}
				b = NN % Answer;
				if (a != b) break;
			}
			if (flag == 1) break;
		}
		if (flag == 0)
			for (int i = 1; i*i < N; i++)
				if (!(N%i))
					Answer = N / i - 1;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}