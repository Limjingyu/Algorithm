#include <iostream>
using namespace std;

int N, M, R, C, L;
int map[52][52];
bool visited[52][52], check[52][52];

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
int access[4][4] = {
	{ 1, 2, 5, 6 },
	{ 1, 2, 4, 7 },
	{ 1, 3, 4, 5 },
	{ 1, 3, 6, 7 },
};

void init() {
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visited[i][j] = false;
			check[i][j] = false;
		}
	}

	return;
}

int countAccess() {
	int sol = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j]) {
				sol++;
			}
		}
	}
	
	return sol;
}

void dfs(int r, int c, int l) {
	if (l == L) {
		return;
	}
	check[r][c] = true;
	
	int i, j, tmp_k;
	for (int k = 0; k < 4; k++) {
		tmp_k = k;
		if (k % 2 == 0) tmp_k++;
		else tmp_k--;
		for (int m = 0; m < 4; m++) {
			if (map[r][c] == access[tmp_k][m]) {
				tmp_k = 4;
				break;
			}
		}
		if (tmp_k != 4) continue;

		i = r + di[k];
		j = c + dj[k];
		visited[r][c] = true;
		if (i >= 0 && i < N && j >= 0 && j < M) {
			for (int m = 0; m < 4; m++) {
				if (map[i][j] == access[k][m] && !visited[i][j]) {
					dfs(i, j, l + 1);
					break;
				}
			}
		}
		visited[r][c] = false;
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		dfs(R, C, 0);
		cout << "#" << t << " " << countAccess() << endl;
	}

	return 0; 
}