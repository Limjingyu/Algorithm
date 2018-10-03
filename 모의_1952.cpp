#include <iostream>
#include <algorithm>
using namespace std;

int month[14];
int dp[4][14];

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		for (int i = 0; i < 4; i++) {
			cin >> dp[i][0];
			dp[i][1] = dp[i][0];
		}
		for (int i = 1; i <= 12; i++) {
			cin >> month[i];
			dp[0][i] = dp[0][0] * month[i];
		}
		
		int minn;
		for (int i = 2; i <= 12; i++) {
			minn = min(dp[0][i - 1], dp[1][i - 1]);
			if (i >= 4) {
				minn = min(minn, dp[2][i - 3]);
			}
			dp[0][i] += minn;
			dp[1][i] = minn + dp[1][0];
			dp[2][i] = minn + dp[2][0];
		}
		minn = min(min(dp[3][0], dp[2][10]), dp[2][11]);
		int min12 = min(min(dp[0][12], dp[1][12]), dp[2][12]);
		
		cout << "#" << t << " " << min(minn, min12) << endl;
	}

	return 0;
}