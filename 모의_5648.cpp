#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

struct Info {
	int i, j;
	int move;
	int K;
};
queue<Info> q;
int map[4002][4002];

int di[4] = { 0,0,-1,1 };
int dj[4] = { 1,-1,0,0 };

void init() {
	int N;
	scanf("%d", &N);
	int i, j, move, k;
	while (!q.empty()) q.pop();
	memset(map, 0, sizeof(map));
	for (int n = 0; n < N; n++) {
		scanf("%d %d %d %d", &i, &j, &move, &k);
		i += 1000;
		j += 1000;
		map[i * 2][j * 2] = k;
		q.push(Info{ i * 2,j * 2, move, k });
	}
}

int bfs() {
	int sol = 0;
	Info now;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		if (map[now.i][now.j] > now.K) {
			sol += map[now.i][now.j];
			map[now.i][now.j] = 0;
			continue;
		}
		map[now.i][now.j] = 0;

		now.i += di[now.move];
		now.j += dj[now.move];
		if (now.i < 0 || now.i > 4000 || now.j < 0 || now.j > 4000)
			continue;

		if (map[now.i][now.j] == 0) q.push(now);
		map[now.i][now.j] += now.K;
	}


	return sol;
}

int main() {
	int TC;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		init();
		printf("#%d %d\n", t, bfs());
	}

	return 0;
}