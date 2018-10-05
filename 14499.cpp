#include <iostream>
#include <algorithm>
using namespace std;

int N, M, i, j, K;
int map[21][21];
int dice[4][3];

int di[5] = { 0, 0, 0, -1, 1 };
int dj[5] = { 0, 1, -1, 0, 0 };

void lotation(int move) {
	if (move == 1) {
		swap(dice[1][1], dice[1][2]);
		swap(dice[1][1], dice[3][1]);
		swap(dice[1][1], dice[1][0]);
	}
	else if (move == 2) {
		swap(dice[1][1], dice[1][0]);
		swap(dice[1][1], dice[3][1]);
		swap(dice[1][1], dice[1][2]);
	}
	else if (move == 3) {
		swap(dice[1][1], dice[0][1]);
		swap(dice[1][1], dice[3][1]);
		swap(dice[1][1], dice[2][1]);
	}
	else if (move == 4) {
		swap(dice[1][1], dice[2][1]);
		swap(dice[1][1], dice[3][1]);
		swap(dice[1][1], dice[0][1]);
	}

	return;
}
int main() {
	cin >> N >> M >> i >> j >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int move;
	for (int k = 0; k < K; k++) {
		cin >> move;
		if (0 <= i + di[move] && i + di[move] < N && 0 <= j + dj[move] && j + dj[move] < M) {
			i += di[move];
			j += dj[move];
			lotation(move);
			if (map[i][j] == 0) {
				map[i][j] = dice[3][1];
			}
			else {
				dice[3][1] = map[i][j];
				map[i][j] = 0;
			}
			cout << dice[1][1] << endl;
		}
	}

	return 0;
}