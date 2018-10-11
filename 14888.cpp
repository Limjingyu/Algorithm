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
	int plus, minus, multiple, divide;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> plus >> minus >> multiple >> divide;
	maxx = -1000000000;
	minn = 1000000000;
	dfs(plus, minus, multiple, divide, num[0], 1);

	cout << maxx << endl << minn << endl;
	
	return 0;
}