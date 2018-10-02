#include <iostream>
using namespace std;

bool map[20][20];

int process() {
	int N, K;
	cin >> N >> K;

	int cell;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cell;
			if (cell == 0) map[i][j] = false;
			else map[i][j] = true;
		}
	}

	int sol = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j]) {
				if (map[i][j - 1]) continue;
				bool flag = true;
				for (int k = 1; k < K; k++) {
					if (!map[i][j + k]) {
						flag = false;
					}
				}
				if (flag && (j + K == N + 1 || !map[i][j + K])) {
					sol++;
					j += (K - 1);
				}
			}
		}
		for (int j = 1; j <= N; j++) {
			if (map[j][i]) {
				if (map[j - 1][i]) continue;
				bool flag = true;
				for (int k = 1; k < K; k++) {
					if (!map[j + k][i]) {
						flag = false;
					}
				}
				if (flag && (j + K == N + 1 || !map[j + K][i])) {
					sol++;
					j += (K - 1);
				}
			}
		}
	}

	return sol;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}