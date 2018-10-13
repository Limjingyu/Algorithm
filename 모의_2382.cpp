#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

struct point {
	int i, j;
};
struct Info {
	int i, j, num, move;
};

bool comp(const Info &a, const Info &b) {
	return a.num < b.num;
}

int N, M, K;
vector<Info> v;
Info map[102][102];
bool visited[102][102];
int di[5] = { 0, -1, 1, 0, 0 };
int dj[5] = { 0, 0, 0, -1, 1 };

void init() {
	cin >> N >> M >> K;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			map[i][j] = { 0, 0, 0, 0 };
		}
	}
	int i, j, num, move;
	v.clear();
	for (int k = 0; k < K; k++) {
		cin >> i >> j >> num >> move;
		map[i][j] = { i, j, num, move };
		v.push_back(Info{ i, j, num, move });
	}
	
	return;
}

int bfs() {
	Info tmp;
	vector<point> pos;
	int i, j;
	for (int time = 0; time < M; time++) {
		sort(v.begin(), v.end(), comp);
		pos.clear();
		// v에서 빼는거랑 새로운 v만들어주는거... 한번에 가능하지 않을까?
		while (!v.empty()) {
			tmp = v[0];
			v.erase(v.begin());

			map[tmp.i][tmp.j].num -= tmp.num;

			tmp.i += di[tmp.move];
			tmp.j += dj[tmp.move];

			if (tmp.i == 0 || tmp.i == N - 1 || tmp.j == 0 || tmp.j == N - 1) {
				if (tmp.num / 2 == 0) continue;
				tmp.num /= 2;
				if (tmp.move % 2 == 1) tmp.move++;
				else tmp.move--;
			}
			map[tmp.i][tmp.j].num += tmp.num;
			map[tmp.i][tmp.j].move = tmp.move;
			pos.push_back(point{ tmp.i, tmp.j });
		}

		int len = pos.size();
		memset(visited, false, sizeof(visited));
		for (int k = 0; k < len; k++) {
			i = pos[k].i;
			j = pos[k].j;
			if (!visited[i][j]) {
				visited[i][j] = true;
				v.push_back(Info{ i, j , map[i][j].num, map[i][j].move });
			}	
		}
	}

	int sol = 0;
	int len = v.size();
	for (int i = 0; i < len; i++) {
		sol += v[i].num;
	}

	return sol;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		cout << "#" << t << " " << bfs() << endl;
	}
	return 0;
}