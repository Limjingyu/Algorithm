#include <iostream>
using namespace std;

int n;
int map[100][100];
int dp[100][100];

int jump(int y, int x) {
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;

	int &ret = dp[y][x];
	if (ret != -1) return ret;
	
	int size = map[y][x];
	return ret = jump(y + size, x) || jump(y, x + size);
}
int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> n;
		for(int j = 0; j <n;j++)
			for(int k = 0; k < n; k++) {
				dp[j][k] = -1;
				cin >> map[j][k];
			}
		
		if (jump(0, 0) == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}