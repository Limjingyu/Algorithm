#include <iostream>
using namespace std;

int N, X;
int map[21][21];
bool used[21];

void init() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	return;
}

int process() {
	int sol = 0;
	bool use;
	for (int i = 0; i < N; i++) {
		//가로검사
		use = true;
		for (int j = 0; j < N; j++) used[j] = false;
		for (int j = 1; j < N; j++) {
			if (map[i][j - 1] == map[i][j]) continue;
			else if (map[i][j - 1] + 1 == map[i][j]) {
				if (j - X < 0) {
					use = false;
					break;
				}
				for (int k = j - X; k < j; k++) {
					if (map[i][k] != map[i][j - 1] || used[k]) {
						use = false;
						break;
					}
					used[k] = true;
				}
			}
			else if (map[i][j] - map[i][j - 1] >=2 ) {
				use = false;
			}
			if (!use) break;
		}
		if (use) {
			for (int j = N - 2; j >= 0; j--) {
				if (map[i][j + 1] == map[i][j]) continue;
				else if (map[i][j + 1] + 1 == map[i][j]) {
					if (j + X >= N) {
						use = false;
						break;
					}
					for (int k = j + X; k > j; k--) {
						if (map[i][k] != map[i][j + 1] || used[k]) {
							use = false;
							break;
						}
						used[k] = true;
					}
				}
				else if (map[i][j] - map[i][j + 1] >= 2) {
					use = false;
				}
				if (!use) break;
			}
		}
		if (use) sol++;

		//세로검사
		use = true;
		for (int j = 0; j < N; j++) used[j] = false;
		for (int j = 1; j < N; j++) {
			if (map[j - 1][i] == map[j][i]) continue;
			else if (map[j - 1][i] + 1 == map[j][i]) {
				if (j - X < 0) {
					use = false;
					break;
				}
				for (int k = j - X; k < j; k++) {
					if (map[k][i] != map[j - 1][i] || used[k]) {
						use = false;
						break;
					}
					used[k] = true;
				}
			}
			else if (map[j][i] - map[j - 1][i] >= 2) {
				use = false;
			}
			if (!use) break;
		}
		if (use) {
			for (int j = N - 2; j >= 0; j--) {
				if (map[j + 1][i] == map[j][i]) continue;
				else if (map[j + 1][i] + 1 == map[j][i]) {
					if (j + X >= N) {
						use = false;
						break;
					}
					for (int k = j + X; k > j; k--) {
						if (map[k][i] != map[j + 1][i] || used[k]) {
							use = false;
							break;
						}
						used[k] = true;
					}
				}
				else if (map[j][i] - map[j + 1][i] >= 2) {
					use = false;
				}
				if (!use) break;
			}
		}
		if (use) sol++;
	}

	return sol;
}
int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		cout << "#" << t << " " << process() << endl;
	}

	return 0;
}