#include <iostream>
using namespace std;

int dp[10003];
int n, k, N[101];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> N[i];
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = N[i]; j <= k; j++) {
			dp[j] += dp[j - N[i]];
		}
	}
	cout << dp[k] << endl;
	return 0;
}