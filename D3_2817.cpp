#include <iostream>
using namespace std;

int n, k, sol;
int input[22];
bool visited[22];

void init() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		visited[i] = false;
	}
	sol = 0;
}
void dfs(int now, int count, int sum) {
	if (sum == k) {
		sol++;
		return;
	}
	if (count == n && sum > k) {
		return;
	}
	for (int i = now; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, count + 1, sum + input[i]);
			visited[i] = false;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		init();
		dfs(0, 0, 0);
		cout << "#" << i << " " << sol << endl;
	}
}