#include <iostream>
using namespace std;

long long dp[10][102];

int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i < 10; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= N; i++) {
		dp[0][i] = dp[1][i - 1];
		for (int j = 1; j <= 8; j++)
			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
		dp[9][i] = dp[8][i - 1];
	}

	long long sol = 0;
	for (int i = 0; i < 10; i++) {
		sol = (sol + dp[i][N]) % 1000000000;
	}

	cout << sol << endl;
	return 0;
}