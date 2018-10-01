/*
«…∫º∞‘¿”

*/

#include <iostream>
using namespace std;

int N;
int map[110][110];
int wormhole[12][3][3];
int start_i, start_j;
int sol;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

void dfs(int i, int j, int go, int score) {
	if ((i == start_i && j == start_j) || map[i][j] == -1) {
		if (sol < score) {
			sol = score;
		}
		return;
	}
	else if (0 == i || i == N + 1 || 0 == j || j == N + 1) { // ∫Æ
		score++;
		if (go == 0) { // ¿ß
			go = 1;
		}
		else if (go == 1) { // æ∆∑°
			go = 0;
		}
		else if (go == 2) { // ø¿
			go = 3;
		}
		else { // øﬁ
			go = 2;
		}
	}
	else if (map[i][j] == 1) {
		score++;
		if (go == 0) {
			go = 1;
		}
		else if (go == 1) {
			go = 2;
		}
		else if (go == 2) {
			go = 3;
		}
		else {
			go = 0;
		}
	}
	else if (map[i][j] == 2) {
		score++;
		if (go == 0) {
			go = 2;
		}
		else if (go == 1) {
			go = 0;
		}
		else if (go == 2) {
			go = 3;
		}
		else {
			go = 1;
		}
	}
	else if (map[i][j] == 3) {
		score++;
		if (go == 0) {
			go = 3;
		}
		else if (go == 1) {
			go = 0;
		}
		else if (go == 2) {
			go = 1;
		}
		else {
			go = 2;
		}
	}
	else if (map[i][j] == 4) {
		score++;
		if (go == 0) {
			go = 1;
		}
		else if (go == 1) {
			go = 3;
		}
		else if (go == 2) {
			go = 0;
		}
		else {
			go = 2;
		}
	}
	else if (map[i][j] == 5) {
		score++;
		if (go == 0) {
			go = 1;
		}
		else if (go == 1) {
			go = 0;
		}
		else if (go == 2) {
			go = 3;
		}
		else {
			go = 2;
		}
	}
	else if (map[i][j] > 5) {
		int temp_i = i, temp_j = j;
		if (wormhole[map[i][j]][0][0] == i && wormhole[map[i][j]][0][j] == j) { // worm1 -> worm2
			i = wormhole[map[temp_i][temp_j]][1][0];
			j = wormhole[map[temp_i][temp_j]][1][1];
		}
		else {
			i = wormhole[map[temp_i][temp_j]][0][0];
			j = wormhole[map[temp_i][temp_j]][0][1];
		}
	}

	dfs(i + di[go], j + dj[go], go, score);

	return;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 6; i < 11; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					wormhole[i][j][k] = -1;
				}
			}
		}
		sol = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
				if (map[i][j] > 5) {
					if (wormhole[map[i][j]][0][0] == -1) {
						wormhole[map[i][j]][0][0] = i;
						wormhole[map[i][j]][0][1] = j;
					}
					else {
						wormhole[map[i][j]][1][0] = i;
						wormhole[map[i][j]][1][1] = j;
					}
				}
			}
			map[i][N + 1] = 0;
			map[N + 1][i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 0) {
					start_i = i;
					start_j = j;
					for (int k = 0; k < 4; k++) {
						dfs(i + di[k], j + dj[k], k, 0);
					}
				}
			}
		}

		cout << "#" << t << " " << sol << endl;
	}

	return 0;
}
