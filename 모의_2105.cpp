#include <iostream>
using namespace std;

int N;
int start_i, start_j;
int sol;
int map[22][22];
int visited[22][22];
bool used[102];

int di[4] = { 1, 1, -1, -1 };
int dj[4] = { 1, -1, -1, 1 };

void dfs(int ii, int jj, bool first, int cnt, int dir) {
	if (ii == start_i && jj == start_j && first) {
		if (sol < cnt && dir == 3) {
			sol = cnt;
		}
		return;
	}
	if (visited[ii][jj]) {
		return;
	}
	
	int i, j;
	for (int k = 0; k < 2; k++) {
		i = ii + di[(dir + k) % 4];
		j = jj + dj[(dir + k) % 4];
		if (i >= 0 && i < N && j >= 0 && j < N && !used[map[i][j]]) {
			visited[ii][jj] = true;
			used[map[i][j]] = true;
			dfs(i, j, true, cnt + 1, (dir + k) % 4);
			visited[ii][jj] = false;
			used[map[i][j]] = false;
		}
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				used[map[i][j]] = false;
			}
		}
		sol = -1;

		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < N - 1; j++) {
				start_i = i;
				start_j = j;
				dfs(i, j, false, 0, 0);
			}
		}
		cout << "#" << t << " " << sol << endl;
	}
	return 0;
}