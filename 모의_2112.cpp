#include <iostream>
using namespace std;

int D, W, K, sol;
bool map[15][22];

void init() {
	cin >> D >> W >> K;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}
	sol = 20;

	return;
}

bool checkMap() {
	int cnt = 0;
	int A, B;
	for (int j = 0; j < W; j++) {
		A = B = 0;
		for (int i = 0; i < D; i++) {
			if (!map[i][j]) {
				A++;
				B = 0;
			}
			else {
				B++;
				A = 0;
			}
			if (A >= K || B >= K) {
				cnt++;
				break;
			}
		}
		if (cnt != j + 1) break;
	}

	return (cnt == W);
}

void dfs(int d, int drug_num) {
	if (drug_num >= sol) return; 
	if (d == D) {
		if (checkMap() && drug_num < sol)
			sol = drug_num;
		return;
	}
	d++;
	
	dfs(d, drug_num); // 현재줄에 투입 X
	bool tmp[22];
	for (int j = 0; j < W; j++) { // A 투입
		tmp[j] = map[d][j];
		map[d][j] = false;
	}
	dfs(d, drug_num + 1);
	for (int j = 0; j < W; j++) { // B 투입
		map[d][j] = true;
	}
	dfs(d, drug_num + 1);
	for (int j = 0; j < W; j++) { // 복구
		map[d][j] = tmp[j];
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		dfs(-1, 0);
		cout << "#" << t << " " << sol << endl;
	}
	return 0;
}