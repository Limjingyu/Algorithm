#include <iostream>
using namespace std;

#define Max(a,b) ((a) > (b) ? (a) : (b))

int n, map[102][102], dp[102][102];

int main() {
	int C;
	cin >> C;
	
	for (int i = 0; i < C; i++) {
		cin >> n;
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				map[j][k] = dp[j][k] = 0;
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= j; k++) {
				cin >> map[j][k];
			}
		}

		dp[1][1] = map[1][1];
		for (int j = 2; j <= n; j++) {
			for (int k = 1; k <= j; k++) {
				dp[j][k] = Max(dp[j - 1][k - 1], dp[j - 1][k]) + map[j][k];
			}
		}
		int sol = dp[n][1];
		for (int j = 2; j <= n; j++) {
			sol = Max(sol, dp[n][j]);
		}
		cout << sol << endl;
	}
	return 0;
}