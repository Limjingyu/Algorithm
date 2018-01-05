#include <iostream>
#include <string>
using namespace std;
#define LIMIT 1000000
int dp[5002];

int main() {
	string input = "";
	int N;
	cin >> input;
	N = input.length();

	if (input[0] == '0') {
		cout << "0" << endl;
		return 0;
	}

	dp[N] = dp[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--) {
		if (input[i] == '0') {
			if ((input[i + 1] == '0') || (i > 0 && input[i - 1] - '0' > 2)) {
				dp[0] = 0;
				break;
			}
			dp[i] = dp[i + 1];
		}
		else if ((input[i] == '1') || (input[i] == '2' && input[i+1] - '0' <= 6)) {
			if (input[i + 1] == '0' || input[i + 2] == '0') {
				dp[i] = dp[i + 1];
			}
			else {
				dp[i] = (dp[i + 1] + dp[i + 2]) % LIMIT;
			}
		}
		else {
			dp[i] = dp[i + 1];
		}
	}
	cout << dp[0] << endl;
	return 0;
}