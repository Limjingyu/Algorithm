#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

#define MAXX 1000002
int dp[1103];

int main() {
	int N, cnt;
	cin >> N;
	memset(dp, MAXX, sizeof(int) * 1103);
	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> cnt;
		for (int j = i + 1; j <= i + cnt; j++) {
			if(dp[j] > dp[i] + 1)
				dp[j] = dp[i] + 1;
		}
	}
	if (dp[N - 1] == dp[N + 99])
		cout << "-1" << endl;
	else
		cout << dp[N - 1] << endl;

	return 0;
}