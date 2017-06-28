#include <iostream>
using namespace std;


int main() {
	int N, K;
	int A[11];

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	int cnt = 0;
	while (1) {
		for (int i = N; i > 0; i--) {
			if (K >= A[i]) {
				K -= A[i];
				cnt++;
				break;
			}
		}
		if (K == 0) break;
	}

	cout << cnt << endl;


	return 0;
}