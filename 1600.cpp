#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int i, j, k;
	int time;
};

int K, H, W;
int map[202][202];
int visited[202][202][32];

int di_h[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dj_h[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int di_m[4] = { -1, 1, 0, 0 };
int dj_m[4] = { 0, 0, -1, 1 };

int bfs() {
	int i, j;
	Info info;
	queue<Info> q;
	q.push(Info{ 1, 1, 0, 0 });
	while (!q.empty()) {
		info = q.front();
		q.pop();
		if (info.i == H && info.j == W) {
			return info.time;
		}
		info.time++;
		for (int k = 0; k < 4; k++) {
			i = info.i + di_m[k];
			j = info.j + dj_m[k];
			if (i < 1 || i > H || j < 1 || j > W || map[i][j] == 1 || visited[i][j][info.k]) continue;
			visited[i][j][info.k] = true;
			q.push(Info{ i, j, info.k, info.time });
		}
		if (info.k < K) {
			info.k++;
			for (int k = 0; k < 8; k++) {
				i = info.i + di_h[k];
				j = info.j + dj_h[k];
				if (i < 1 || i > H || j < 1 || j > W || map[i][j] == 1 || visited[i][j][info.k]) continue;
				visited[i][j][info.k] = true;
				q.push(Info{ i, j, info.k, info.time });
			}
		}
	}

	return -1;
}

int main() {
	cin >> K >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}

	cout << bfs() << endl;

	return 0;
}