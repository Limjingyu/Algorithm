#include <iostream>
using namespace std;

int N, M;
int map[52][52];

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void dfs(int r, int c, int d) {
	map[r][c] = 2;

	for (int i = 0; i < 4; i++) {
		if (d == 0) d = 3;
		else d--;
		if (r + dr[d] >= 0 && r + dr[d] < N && 
			c + dc[d] >= 0 && c + dc[d] < M &&
			map[r + dr[d]][c + dc[d]] == 0) {
			dfs(r + dr[d], c + dc[d], d);
			return;
		}
	}

	int tmp = d;
	d -= 2;
	if (d < 0) d += 4;
	if (map[r + dr[d]][c + dc[d]] != 1) {
		dfs(r + dr[d], c + dc[d], tmp);
	}

	return;
}

int main() {
	int r, c, d;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	dfs(r, c, d);

	int sol = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				sol++;
			}
		}
	}

	cout << sol << endl;

	return 0;
}