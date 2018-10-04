#include <iostream>
using namespace std;

int N, num[15];
int maxx, minn;

void dfs(int plus, int minus, int multiple, int divide, int sol, int n) {
	if (n == N) {
		if (sol > maxx)
			maxx = sol;
		if (sol < minn)
			minn = sol;

		return;
	}

	if (plus > 0) {
		dfs(plus - 1, minus, multiple, divide, sol + num[n], n + 1);
	}
	if (minus > 0) {
		dfs(plus, minus - 1, multiple, divide, sol - num[n], n + 1);
	}
	if (multiple > 0) {
		dfs(plus, minus, multiple - 1, divide, sol * num[n], n + 1);
	}
	if (divide > 0) {
		dfs(plus, minus, multiple, divide - 1, sol / num[n], n + 1);
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	int plus, minus, multiple, divide;
	for (int t = 1; t <= TC; t++) {
		cin >> N;
		cin >> plus >> minus >> multiple >> divide;
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		maxx = -100000000;
		minn = 100000000;
		dfs(plus, minus, multiple, divide, num[0], 1);

		cout << "#" << t << " " << maxx - minn << endl;
	}
	return 0;
}