#include <iostream>
using namespace std;

int N, L, T[22], K[22], sol;
bool visited[22];

void init() {
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> K[i];
		visited[i] = false;
	}
	sol = -1;
}

void dfs(int nowI, int nowT, int nowK) {
	if (nowT > sol) sol = nowT;
	for (int i = nowI; i <= N; i++) {
		if (!visited[i] && K[i] <= nowK) {
			visited[i] = true;
			dfs(i + 1, nowT + T[i], nowK - K[i]);
			visited[i] = false;
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		init();
		dfs(1, 0, L);
		cout << "#" << i << " " << sol << endl;
	}
}