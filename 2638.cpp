#include <iostream>
#include <queue>
using namespace std;

struct point {
	int i, j;
};
int N, M, sizee;
int map[102][102];
queue<point> q, out;
bool visited[102][102];

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void setOutSide() {
	point pos, tmp;
	while (!out.empty()) {
		pos = out.front();
		out.pop();
		map[pos.i][pos.j] = -1;
		for (int k = 0; k < 4; k++) {
			tmp.i = pos.i + di[k];
			tmp.j = pos.j + dj[k];
			if (tmp.i > 0 && tmp.i <= N && tmp.j > 0 && tmp.j <= M) {
				if (map[tmp.i][tmp.j] == 0 && !visited[tmp.i][tmp.j]) {
					visited[tmp.i][tmp.j] = true;
					out.push(tmp);
				}
			}
		}
	}
	
	return;
}

int bfs() {
	int time = 0;
	int cnt;
	int now_size;
	point pos;
	while (!q.empty()) {
		setOutSide();
		time++;
		now_size = sizee;
		for (int i = 0; i < now_size; i++) {
			pos = q.front();
			q.pop();
			cnt = 0;
			for (int k = 0; k < 4; k++) {
				if (map[pos.i + di[k]][pos.j + dj[k]] == -1) {
					cnt++;
				}
			}
			if (cnt >= 2) {
				sizee--;
				out.push(pos);
			}
			else {
				q.push(pos);
			}
		}
	}

	return time;
}

int main() {
	cin >> N >> M;
	point tmp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				tmp.i = i;
				tmp.j = j;
				q.push(tmp);
				sizee++;
			}
		}
	}
	out.push(point{ 1, 1 });
	visited[1][1] = true;
	cout << bfs() << endl;

	return 0;
}