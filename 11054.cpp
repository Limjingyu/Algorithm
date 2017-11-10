#include <iostream>
using namespace std;

int A[1002];
int dp[2][1002];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++) {
		if(dp[0][i] == 0) dp[0][i] = 1;
		for (int j = i + 1; j < N; j++)
			if (A[j] > A[i])
				dp[0][j] = dp[0][i] + 1 > dp[0][j] ? dp[0][i] + 1 : dp[0][j];
		if (dp[1][N - 1 - i] == 0) dp[1][N - 1 - i] = 1;
		for (int j = N - i - 1; j >= 0; j--) 
			if (A[j] > A[N - 1 - i])
				dp[1][j] = dp[1][N - 1 - i] + 1 > dp[1][j] ? dp[1][N - 1 - i] + 1 : dp[1][j];
	}

	int sol = 0, now;
	for (int i = 0; i < N; i++) {
		now = dp[0][i] + dp[1][i] - 1;
		if (now > sol) sol = now;
	}
	cout << sol << endl;
	return 0;
}