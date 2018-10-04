#include <iostream>
#include <memory.h>
using namespace std;

int N;
int sol = 0;

void dfs(int map[21][21], int n) {
	if (n == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (sol < map[i][j])
					sol = map[i][j];
			}
		}

		return;
	}

	int tmp;
	int now[21][21];
	// ¿Þ
	memcpy(now, map, sizeof(now));
	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int j = 1; j < N; j++) {
			if (now[i][j] != 0) {
				if (now[i][tmp] == now[i][j]) {
					now[i][tmp] += now[i][j];
					now[i][j] = 0;
				}
				else {
					if (now[i][tmp] == 0) {
						now[i][tmp] = now[i][j];
						now[i][j] = 0;
						tmp--;
					}
					else {
						now[i][tmp + 1] = now[i][j];
						if (tmp + 1 != j) now[i][j] = 0;
					}
				}
				tmp++;
			}
		}
	}
	dfs(now, n + 1);
	// ¿À
	memcpy(now, map, sizeof(now));
	for (int i = 0; i < N; i++) {
		tmp = N - 1;
		for (int j = N - 2; j >= 0; j--) {
			if (now[i][j] != 0) {
				if (now[i][tmp] == now[i][j]) {
					now[i][tmp] += now[i][j];
					now[i][j] = 0;
				}
				else {
					if (now[i][tmp] == 0) {
						now[i][tmp] = now[i][j];
						now[i][j] = 0;
						tmp++;
					}
					else {
						now[i][tmp - 1] = now[i][j];
						if (tmp - 1 != j) now[i][j] = 0;
					}
				}
				tmp--;
			}
		}
	}
	dfs(now, n + 1);
	// ¾Æ·¡
	memcpy(now, map, sizeof(now));
	for (int i = 0; i < N; i++) {
		tmp = N - 1;
		for (int j = N - 2; j >= 0; j--) {
			if (now[j][i] != 0) {
				if (now[tmp][i] == now[j][i]) {
					now[tmp][i] += now[j][i];
					now[j][i] = 0;
				}
				else {
					if (now[tmp][i] == 0) {
						now[tmp][i] = now[j][i];
						now[j][i] = 0;
						tmp++;
					}
					else {
						now[tmp - 1][i] = now[j][i];
						if (tmp - 1 != j) now[j][i] = 0;
					}
				}
				tmp--;
			}
		}
	}
	dfs(now, n + 1);
	// À§
	memcpy(now, map, sizeof(now));
	for (int i = 0; i < N; i++) {
		tmp = 0;
		for (int j = 1; j < N; j++) {
			if (now[j][i] != 0) {
				if (now[tmp][i] == now[j][i]) {
					now[tmp][i] += now[j][i];
					now[j][i] = 0;
				}
				else {
					if (now[tmp][i] == 0) {
						now[tmp][i] = now[j][i];
						now[j][i] = 0;
						tmp--;
					}
					else {
						now[tmp + 1][i] = now[j][i];
						if (tmp + 1 != j) now[j][i] = 0;
					}
				}
				tmp++;
			}
		}
	}
	dfs(now, n + 1);

	return;
}
int main() {
	cin >> N;
	int map[21][21];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(map, 0);
	cout << sol << endl;

	return 0;
}