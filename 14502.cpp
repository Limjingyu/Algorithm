#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct point {
	int i, j;
};
int N, M;
int input[10][10];
bool visited[10][10];
int maxx = 0;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

int bfs() {
	int ii, jj;
	queue<point> q;
	point temp, temp2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 2) { 
				temp.i = i;
				temp.j = j;
				q.push(temp);
				while (!q.empty()) {
					temp = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						ii = temp.i + di[k];
						jj = temp.j + dj[k];
						if (0 < ii && ii <= N && 0 < jj && jj <= M && input[ii][jj] == 0) {
							input[ii][jj] = 3;
							temp2.i = ii;
							temp2.j = jj;
							q.push(temp2);
						}
					}
				}
			}
		}
	}
	
	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (input[i][j] == 0) {
				count++;
			}
			if (input[i][j] == 3) {
				input[i][j] = 0;
			}
		}
	}

	return count;
}

void dfs(int ii, int jj, int wall) {
	if (wall == 3) {
		maxx = max(maxx, bfs());
		return;
	}

	for (int i = ii; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == ii && j == 1) j = jj;
			if (!visited[i][j] && input[i][j] == 0) {
				input[i][j] = 1;
				visited[i][j] = true;
				dfs(i, j, wall + 1);
				input[i][j] = 0;
				visited[i][j] = false;
			}
		}
	}

	return;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input[i][j];
		}
	}
	dfs(1, 1, 0);

	cout << maxx << endl;

	return 0;
}

