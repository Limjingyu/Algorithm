#include <iostream>
#include <queue>
using namespace std;

struct point {
	int w, h;
};
int N, W, H;
int sol;
int map[20][20];

void count() {
	int cnt = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] != 0) {
				cnt++;
			}
		}
	}
	if (cnt < sol) {
		sol = cnt;
	}

	return;
}

void check(int i) {
	queue<point> q;
	for (int j = 1; j <= H; j++) {
		if (map[j][i] != 0) {
			q.push(point{ i, j });
			break;
		}
	}
	point tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		int len = map[tmp.h][tmp.w];
		map[tmp.h][tmp.w] = -1;
		if (len > 1) {
			for (int w = tmp.w - 1; w >= 1 && tmp.w - w < len; w--) {
				if (map[tmp.h][w] > 0) {
					q.push(point{ w, tmp.h });
				}
			}
			for (int w = tmp.w + 1; w <= W && w - tmp.w < len; w++) {
				if (map[tmp.h][w] > 0) {
					q.push(point{ w, tmp.h });
				}
			}
			for (int h = tmp.h - 1; h >= 1 && tmp.h - h < len; h--) {
				if (map[h][tmp.w] > 0) {
					q.push(point{ tmp.w, h });
				}
			}
			for (int h = tmp.h + 1; h <= H && h - tmp.h < len; h++) {
				if (map[h][tmp.w] > 0) {
					q.push(point{ tmp.w, h });
				}
			}
		}
	}

	return;
}
void erase() {
	int gap;
	bool flag;
	for (int w = 1; w <= W; w++) {
		gap = 0;
		flag = false;
		for (int h = H; h >= 1; h--) {
			if (map[h][w] == -1) {
				gap++;
				flag = true;
				map[h][w] = 0;
			}
			else if (map[h][w] == 0) {
				break;
			}
			else if (flag) {
				map[h + gap][w] = map[h][w];
				map[h][w] = 0;
			}
		}
	}
	
	return;
}

void mapCopy(int(*a)[20], int(*b)[20]) {
	for (int i = 1; i < 20; i++)
		for (int j = 1; j < 20; j++)
			a[i][j] = b[i][j];
}

void dfs(int n) {
	if (n == N) {
		count();
		return;
	}

	int now[20][20];
	for (int i = 1; i <= W; i++) {
		mapCopy(now, map);
		check(i);
		erase();
		dfs(n + 1);
		mapCopy(map, now);
	}
	
	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N >> W >> H;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
			}
		}
		sol = 300;
		dfs(0);

		cout << "#" << t << " " << sol << endl;
	}

	return 0;
}