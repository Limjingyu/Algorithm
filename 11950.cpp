#include <iostream>
#include <algorithm>
using namespace std;

int DP[4][52] = { 9999, };

int main() {
	int N, M;
	int W, B, R;
	char A;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		W = B = R = 0;
		for (int j = 1; j <= M; j++) {
			cin >> A;
			if (A == 'W') {
				W++;
			}
			else if (A == 'B') {
				B++;
			}
			else {
				R++;
			}
		}
		if (i == 1) {
			DP[1][i] = B + R;
		}
		else if (i == 2) {
			DP[1][i] = DP[1][i - 1] + (B + R);
			DP[2][i] = DP[1][i - 1] + (W + R);
		}
		else if (i == 3) {
			DP[1][i] = DP[1][i - 1] + (B + R);
			DP[2][i] = min(DP[1][i - 1], DP[2][i - 1]) + (W + R);
			DP[3][i] = DP[2][i - 1] + (W + B);
		}
		else {
			DP[1][i] = DP[1][i - 1] + (B + R);
			DP[2][i] = min(DP[1][i - 1], DP[2][i - 1]) + (W + R);
			DP[3][i] = min(DP[2][i - 1], DP[3][i - 1]) + (W + B);
		}

	}

	cout << DP[3][N] << endl;

	return 0;
}