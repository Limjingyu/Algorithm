#include <iostream>
#include <queue>
using namespace std;

struct Info {
	int i, j;
	int init_life;
	int now_life;
	int time;
};
queue<Info> q[12];
int N, M, K;
bool visited[500][500];

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void init() {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			visited[i][j] = false;
		}
	}
	for (int q_num = 10; q_num > 0; q_num--) {
		while (!q[q_num].empty()) {
			q[q_num].pop();
		}
	}
	return;
}

int bfs() {
	int sizee, sol = 0;
	Info tmp;
	for (int time = 0; time < K; time++) {
		for (int q_num = 10; q_num > 0; q_num--) {
			sizee = q[q_num].size();
			for(int s = 0; s < sizee; s++) {
				tmp = q[q_num].front();
				q[q_num].pop();
				if (tmp.time != time) {
					q[tmp.now_life].push(tmp);
					continue;
				}

				if (tmp.now_life > 0) {
					tmp.now_life--;
					tmp.time++;
					if (tmp.now_life == 0) q[tmp.init_life].push(tmp);
					else q[tmp.now_life].push(tmp);
				}
				else if(tmp.now_life == 0) {
					for (int k = 0; k < 4; k++) {
						int ii = tmp.i + di[k];
						int jj = tmp.j + dj[k];
						if (!visited[ii][jj]) {
							visited[ii][jj] = true;
							q[tmp.init_life].push(Info{ ii,jj,tmp.init_life ,tmp.init_life,tmp.time + 1 });
						}
					}
					if (time + tmp.init_life > K) {
						sol++;
					}
				}
			}
		}
	}
	for (int q_num = 10; q_num > 0; q_num--) {
		sol += q[q_num].size();
	}

	return sol;
}

int main() {
	int TC, tmp;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N >> M >> K;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tmp;
				if (tmp != 0) {
					visited[i + 200][j + 200] = true;
					q[tmp].push(Info{ i + 200, j + 200, tmp, tmp, 0 });
				}
			}
		}
		cout << "#" << t << " " << bfs() << endl;
	}

	return 0;
}