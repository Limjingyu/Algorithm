#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, NN, sol;
int S[22][22];
bool team[22];

void dfs(int ii, int n) {
	if (n == NN) {
		vector<int> v1, v2;
		int len1, len2;
		int team1 = 0, team2 = 0;
		for (int i = 1; i <= N; i++) {
			if (team[i]) {
				len1 = v1.size();
				for (int j = 0; j < len1; j++) {
					team1 += (S[i][v1[j]] + S[v1[j]][i]);
				}
				v1.push_back(i);
			}
			else {
				len2 = v2.size();
				for (int j = 0; j < len2; j++) {
					team2 += (S[i][v2[j]] + S[v2[j]][i]);
				}
				v2.push_back(i);
			}
		}
		if (sol > abs(team1 - team2)) {
			sol = abs(team1 - team2);
		}
		return;
	}

	for (int i = ii + 1; i <= N; i++) {
		team[i] = true;
		dfs(i, n + 1);
		team[i] = false;
	}

	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S[i][j];
		}
	}
	NN = N / 2;
	sol = 987654321;
	memset(team, false, sizeof(team));

	for (int j = 1; j <= NN; j++) {
		team[j] = true;
		dfs(j, 1);
		team[j] = false;
	}
	cout << sol << endl;
	
	return 0;
}