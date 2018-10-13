#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, sol;
bool map[32][12] = { false, };

bool checkMap() {
	int col;
	for (int i = 1; i < N; i++) {
		col = i;
		for(int row = 1; row <= H; row++) {
			if (map[row][col]) col++;
			else if (map[row][col - 1]) col--;
		}
		if (col != i) return false;
	}
	return true;
}

void dfs(int now_c, int now_h, int add) {
	if (add >= sol) return;
	if (checkMap()) {
		sol = min(sol, add);
		return;
	}

	for (int col = now_c; col < N; col++) {
		for (int h = 1; h <= H; h++) {
			if (col == now_c && h == 1) h = now_h;
			if (!map[h][col] && !map[h][col + 1] && !map[h][col - 1]) {
				map[h][col] = true;
				dfs(col, h, add + 1);
				map[h][col] = false;
			}
		}
	}

	return;
}

int main() {
	cin >> N >> M >> H;
	int h, n;
	for (int m = 0; m < M; m++) {
		cin >> h >> n;
		map[h][n] = true;
	}
	sol = 4;
	dfs(1, 1, 0);

	if (sol == 4) sol = -1;
	cout << sol << endl;
	return 0; 
}