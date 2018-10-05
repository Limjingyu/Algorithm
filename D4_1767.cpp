#include <iostream>
using namespace std;

int N;
int input[14][14];
int sol[14];

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input[i][j];
		}
		sol[i] = 987654321;
	}
}

void dfs(int in_i, int in_j, int depth, int now) {
	if(now < sol[depth])
		sol[depth] = now;

	for (int i = in_i; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == in_i && j == 1) j = in_j + 1;
			if (input[i][j] == 1) {
				input[i][j] = 3;
				if (i == 1 || i == N || j == 1 || j == N) {
					dfs(i, j, depth + 1, now);
				}
				else {
					int ii, jj, add;
					for (int k = 0; k < 4; k++) {
						ii = i;
						jj = j;
						add = 0;
						while (0 < ii + di[k] && ii + di[k] <= N
							&& 0 < jj + dj[k] && jj + dj[k] <= N
							&& input[ii + di[k]][jj + dj[k]] == 0) {
							input[ii + di[k]][jj + dj[k]] = 2;
							ii += di[k];
							jj += dj[k];
							add++;
						}
						if ((ii == 1 || ii == N || jj == 1 || jj == N)){
							dfs(i, j, depth + 1, now + add);
						}
						while (input[ii][jj] == 2) {
							input[ii][jj] = 0;
							ii -= di[k];
							jj -= dj[k];
						}
					}
				}
				input[i][j] = 1;
			}
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		init();
		dfs(1, 1, 0, 0);
		cout << "#" << i << " ";
		for (int j = N; j > 0; j--) {
			if (sol[j] != 987654321) {
				cout << sol[j] << endl;
				break;
			}
		}
	}
}