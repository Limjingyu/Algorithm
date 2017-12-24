#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T, N, M;
	unsigned long long sol, nob;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		N = min(N, M - N);
		sol = 1; nob = 1;
		for (int i = 1; i <= N; i++) {
			sol *= M--;
			nob *= i;
		}
		cout << sol/nob << endl;	
	}
	return 0;
}