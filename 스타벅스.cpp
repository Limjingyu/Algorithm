#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;


	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, M, K;
		int MM[21][2] = { 0, };
		Answer = 0;
		cin >> N >> M >> K;

		int j;
		for (int i = 1; i <= N; i++) {
			cin >> j;
			MM[j][0]++;;
		}
		int hab = 0;
		for (int i = 1; i <= M; i++) {
			cin >> MM[i][1];
			hab += MM[i][0] * MM[i][1];

			if (hab > K) {
				Answer = 1;
			}
		}


		cout << "Case #" << test_case + 1 << endl;
		if (Answer == 0) cout << "Y" << endl;
		else cout << "N" << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}