#include <iostream>
#include <algorithm>
using namespace std;

int input[2][100002], dp[2][100002];
int main() {
	int TC, N;
	cin >> TC;
	for (int t = 0; t < TC; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> input[0][i];
		for (int i = 1; i <= N; i++) cin >> input[1][i];

		dp[0][1] = input[0][1];
		dp[1][1] = input[1][1];
		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + input[0][i];
			dp[1][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]) + input[1][i];
		}

		cout << max(dp[0][N], dp[1][N]) << endl;
	}
	return 0;
}