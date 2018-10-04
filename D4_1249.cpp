#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[102][102];
int sol[102][102];
bool visited[102][102];

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

typedef struct point{
	int i;
	int j;
	int k;
}point;

void init() {
	cin >> N;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= N; j++) {
			map[i][j] = int(str[j - 1] - '0');
			sol[i][j] = map[i][j];
			visited[i][j] = false;
		}
	}
}

void bfs() {
	queue<point> q;
	point temp = { 1,1,0 };
	q.push(temp);

	int i, j, k;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		k = q.front().k;
		q.pop();
		visited[i][j] = true;
		if (i == N && j == N) {
			continue;
		}
		for (int d = 0; d < 4; d++) {
			if (0 < i + di[d] && i + di[d] <= N && 0 < j + dj[d] && j + dj[d] <= N) {
				if ((!visited[i + di[d]][j + dj[d]])
					|| k + map[i + di[d]][j + dj[d]] < sol[i + di[d]][j + dj[d]]) {
					temp.i = i + di[d];
					temp.j = j + dj[d];
					sol[i + di[d]][j + dj[d]] = temp.k = k + map[i + di[d]][j + dj[d]];
					q.push(temp);
					visited[i + di[d]][j + dj[d]] = true;
				}
			}
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		init();
		bfs();
		cout << "#" << i << " " << sol[N][N] << endl;
	}
}