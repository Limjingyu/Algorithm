#include <iostream>
#include <algorithm>
using namespace std;

int N, sol;
int T[22], P[22], dp[22];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	sol = -1;
	for (int i = N; i > 0; i--) {
		if (i + T[i] <= N + 1) {
			for (int j = i + T[i]; j <= N; j++) {
				dp[i] = max(dp[i], dp[j]);
			}
			dp[i] += P[i];
		}
		else {
			dp[i] = dp[i + T[i]];
		}
		sol = max(sol, dp[i]);
	}
	cout << sol << endl;

	return 0;
}