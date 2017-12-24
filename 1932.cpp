#include <iostream>
#include <algorithm>
using namespace std;

int top[502][502];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> top[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			top[i][j] = top[i][j] + max(top[i - 1][j - 1], top[i - 1][j]);
		}
	}
	int maxx = top[n][1];
	for (int i = 2; i <= n; i++) {
		maxx = max(maxx, top[n][i]);
	}

	cout << maxx << endl;
	return 0;
}