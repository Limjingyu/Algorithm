#include <iostream>
#include <vector>
using namespace std;

struct Info {
	int time, dir;
};
int N, K, L;
int map[102][102];
vector<Info> turn;
int pos;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
int changeDir[4][2] = {
	{ 2, 3 },
	{ 3, 2 },
	{ 1, 0 },
	{ 0, 1 },
};

int process() {
	int ret = 0;
	int move = 3;
	int tail_move = 3;
	int i = 1, j = 1;
	int tail_i = 1, tail_j = 1;
	while (true) {
		ret++;

		i += di[move];
		j += dj[move];
		if (i < 1 || i > N || j < 1 || j > N || map[i][j] < 4) break;

		if (map[i][j] == 4) { // ºóÄ­
			tail_move = map[tail_i][tail_j];
			map[tail_i][tail_j] = 4;
			tail_i += di[tail_move];
			tail_j += dj[tail_move];
		}
		map[i][j] = move;

		if (ret == turn[pos].time) {
			move = changeDir[move][turn[pos].dir];
			map[i][j] = move;
			pos++;
		}
	}

	return ret;
}

int main() {
	cin >> N >> K;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			map[i][j] = 4;
		}
	}
	for (int k = 0; k < K; k++) {
		cin >> i >> j;
		map[i][j] = 5;
	}
	cin >> L;
	int time, dir;
	char ch;
	for (int l = 0; l < L; l++) {
		cin >> time >> ch;
		if (ch == 'L') dir = 0;
		else dir = 1;
		turn.push_back(Info{ time, dir });
	}
	turn.push_back(Info{ -1, -1 });

	map[1][1] = 3;
	pos = 0;
	cout << process() << endl;

	return 0;
}