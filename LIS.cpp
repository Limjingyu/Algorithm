#include <iostream>
#include <algorithm>
using namespace std;

int n, map[501], dp[501];

int lis(int start) {
	int &ret = dp[start];

	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (map[start] < map[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}
int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> map[j]; 
			dp[j] = -1;
		}
		
		int maxlen = 0;
		for (int j = 0; j < n; j++) {
			maxlen = max(maxlen, lis(j));
		}
		cout << maxlen << endl;
	}
	return 0;
}