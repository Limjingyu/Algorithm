#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arrP[30], arrS[30];
int sol;

void dfs(int ii, int n, int s) {
	if (n > N) {
		sol = max(sol, s - arrS[ii]);
		return;
	}
	sol = max(sol, s);
	if (ii == M) {
		return;
	}


	for (int i = ii + 1; i < M; i++) {
		dfs(i, n + arrP[i], s + arrS[i]);
	}

	return;
}

int main(void) {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> arrP[i] >> arrS[i];
		}
		sol = 0;
		for (int i = 0; i < M; i++) {
			dfs(i, arrP[i], arrS[i]);
		}
		cout << "#" << t << " " << sol << endl;
	}

	return 0;
}