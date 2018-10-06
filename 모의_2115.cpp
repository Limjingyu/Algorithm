#include <iostream>
#include <algorithm>
using namespace std;

int N, M, C;
int sol;
int map[11][11];
int honey[2][6];

int maxData(int people, int jj, int c, int h) {
	if (jj == M && c > C) {
		return h - (honey[people][jj - 1] * honey[people][jj - 1]);
	}
	if (c + honey[people][jj] > C) {
		return h;
	}

	int maxx = h;
	for (int j = jj; j < M; j++) {
		maxx = max(maxx, maxData(people, j + 1, c + honey[people][j], h + (honey[people][j] * honey[people][j])));
	}

	return maxx;
}

void dfs(int ii, int jj, int people) {
	if (people == 2) {
		int tmp = 0;
		for (int i = 0; i < 2; i++) {
			int maxx = 0;
			for (int j = 0; j < M; j++) {
				maxx = max(maxx, maxData(i, j, 0, 0));
			}
			tmp += maxx;
		}
		sol = max(sol, tmp);
		return;
	}

	for (int i = ii; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == ii && j == 0) {
				j = jj;
			}
			if (j == N) continue;
			if (j + M <= N) {
				for (int k = 0; k < M; k++) {
					honey[people][k] = map[i][j + k];
				}
				dfs(i, j + M, people + 1);
			}
		}
	}

	return;
}

int main(void) {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		sol = 0;
		dfs(0, 0, 0);

		cout << "#" << t << " " << sol << endl;
	}

	return 0;
}