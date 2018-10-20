#include <iostream>
using namespace std;

int N, M, sol;
int select[3];
bool check[202][202];

void dfs(int ii, int n) {
	if (n == 3) {
		if (!check[select[0]][select[1]] && !check[select[0]][select[2]] && !check[select[1]][select[2]])
			sol++;
		return;
	}
	for (int i = ii; i <= N; i++) {
		select[n] = i;
		dfs(i + 1, n + 1);
	}

	return;
}

int main() {
	cin >> N >> M;
	int first, second;
	for (int i = 0; i < M; i++) {
		cin >> first >> second;
		check[first][second] = true;
		check[second][first] = true;
	}
	
	dfs(1, 0);
	cout << sol << endl;

	return 0;
}