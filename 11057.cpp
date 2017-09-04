#include <iostream>
using namespace std;

int n;
int D[1001][10] = { 0, };

int main() {

	cin >> n;
	for (int i = 0; i < 10; i++) {
		D[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k >= 0; k--) {
				D[i][j] += (D[i - 1][k]) % 10007;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += (D[n][i]) % 10007;
	}
	cout << sum % 10007 << endl;

	return 0;
}