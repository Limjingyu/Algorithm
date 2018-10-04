#include <iostream>
#include <vector>
using namespace std;

struct point {
	int i, j;
};

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int N, K, sol;
int map[10][10];
bool viseted[10][10];
vector<point> top;

void init() {
	cin >> N >> K;
	int maxx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (maxx < map[i][j])
				maxx = map[i][j];
			viseted[i][j] = false;
		}
	}
	if(!top.empty()) top.clear();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (maxx == map[i][j])
				top.push_back(point{ i, j });
		}
	}
	sol = 0;

	return;
}

void dfs(int i, int j, int depth, bool use) {
	bool move_flag = false;
	
	int ii, jj;
	for (int k = 0; k < 4; k++) {
		ii = i + di[k];
		jj = j + dj[k];
		if (ii < 1 || ii > N || jj < 1 || jj > N || viseted[ii][jj])
			continue;
		if (map[i][j] > map[ii][jj]) {
			move_flag = true;
			viseted[ii][jj] = true;
			dfs(ii, jj, depth + 1, use);
			viseted[ii][jj] = false;
		}
		if (!use) {
			for (int d = 1; d <= K; d++) {
				if (map[i][j] > map[ii][jj] - d) {
					move_flag = true;
					map[ii][jj] -= d;
					viseted[ii][jj] = true;
					dfs(ii, jj, depth + 1, true);
					map[ii][jj] += d;
					viseted[ii][jj] = false;
				}
			}
		}
	}

	if (!move_flag) {
		if (sol < depth) {
			sol = depth;
		}
	}

	return;
}
int main() {
	int TC, top_size;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		top_size = top.size();
		for (int i = 0; i < top_size; i++) {
			viseted[top[i].i][top[i].j] = true;
			dfs(top[i].i, top[i].j, 1, false);
			viseted[top[i].i][top[i].j] = false;
		}
		cout << "#" << t << " " << sol << endl;
	}
	return 0;
}