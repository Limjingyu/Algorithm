#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
	int i, j;
	int type;
};

int N, M;
int map[10][10];
int countt[10][10];
vector<Info> v;
int totalCnt;
int sol;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

void checkZero(int i, int j, int move) {
	while (0 <= i && i < N && 0 <= j && j < M && map[i][j] != 6) {
		if (map[i][j] <= 0) {
			map[i][j] = -1;
			countt[i][j]++;
		}
		i += di[move];
		j += dj[move];
	}

	return;
}

void eraseMinus(int i, int j, int move) {
	while (0 <= i && i < N && 0 <= j && j < M && map[i][j] != 6) {
		if (map[i][j] == -1) {
			countt[i][j]--;
			if (countt[i][j] == 0) {
				map[i][j] = 0;
			}
		}
		i += di[move];
		j += dj[move];
	}

	return;
}

int countZero() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)
				tmp++;
		}
	}

	return tmp;
}

void dfs(int cntt) {
	if (cntt == totalCnt) {
		sol = min(sol, countZero());
		return;
	}

	if (v[cntt].type == 1) {
		for (int move = 0; move < 4; move++) {
			checkZero(v[cntt].i, v[cntt].j, move);
			dfs(cntt + 1);
			eraseMinus(v[cntt].i, v[cntt].j, move);
		}
	}
	else if (v[cntt].type == 2) {
		for (int move = 0; move < 2; move++) {
			checkZero(v[cntt].i, v[cntt].j, move);
			checkZero(v[cntt].i, v[cntt].j, (move + 2) % 4);
			dfs(cntt + 1);
			eraseMinus(v[cntt].i, v[cntt].j, move);
			eraseMinus(v[cntt].i, v[cntt].j, (move + 2) % 4);
		}
	}
	else if (v[cntt].type == 3) {
		for (int move = 0; move < 4; move++) {
			checkZero(v[cntt].i, v[cntt].j, move);
			checkZero(v[cntt].i, v[cntt].j, (move + 1) % 4);
			dfs(cntt + 1);
			eraseMinus(v[cntt].i, v[cntt].j, move);
			eraseMinus(v[cntt].i, v[cntt].j, (move + 1) % 4);
		}
	}
	else if (v[cntt].type == 4) {
		for (int move = 0; move < 4; move++) {
			checkZero(v[cntt].i, v[cntt].j, (move + 3) % 4);
			checkZero(v[cntt].i, v[cntt].j, move);
			checkZero(v[cntt].i, v[cntt].j, (move + 1) % 4);
			dfs(cntt + 1);
			eraseMinus(v[cntt].i, v[cntt].j, (move + 3) % 4);
			eraseMinus(v[cntt].i, v[cntt].j, move);
			eraseMinus(v[cntt].i, v[cntt].j, (move + 1) % 4);
		}
	}

	return;
}

int main(void) {
	cin >> N >> M;
	Info tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (0 < map[i][j] && map[i][j] < 5) {
				tmp.i = i;
				tmp.j = j;
				tmp.type = map[i][j];
				v.push_back(tmp);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 5) {
				for (int move = 0; move < 4; move++) {
					checkZero(i, j, move);
				}
			}
		}
	}
	sol = 987654321;
	totalCnt = v.size();
	dfs(0);

	cout << sol << endl;

	return 0;
}