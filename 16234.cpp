#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

struct point {
	int i, j;
};
int N, L, R;
int map[52][52];
int visited[52][52];

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void setting(int ava, int cell_num) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == cell_num) {
				map[i][j] = ava;
			}
		}
	}

	return;
}

int bfs() {
	queue<point> q;
	int time = 0;
	int cell_num, lr;
	bool flag;
	int sum, cnt;
	point now, side;
	while (true) {
		flag = false;
		cell_num = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					sum = 0;
					cnt = 0;
					cell_num++;
					visited[i][j] = cell_num;
					q.push(point{ i,j });
					while (!q.empty()) {
						now = q.front();
						q.pop();
						sum += map[now.i][now.j];
						cnt++;
						for (int k = 0; k < 4; k++) {
							side.i = now.i + di[k];
							side.j = now.j + dj[k];
							if (side.i < 0 || side.i >= N || side.j < 0 || side.j >= N || visited[side.i][side.j] != 0)
								continue;
							lr = abs(map[side.i][side.j] - map[now.i][now.j]);
							if (L <= lr && lr <= R) {
								flag = true;
								visited[side.i][side.j] = cell_num;
								q.push(side);
							}
						}
					}
					if (cnt > 1) {
						setting(sum / cnt, cell_num);
					}
				}
			}
		}

		if (!flag) break;
		time++;
	}

	return time;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs() << endl;
}