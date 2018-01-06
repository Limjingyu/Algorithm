#include <iostream>
using namespace std;

int main() {
	unsigned long long N, sol = 0;
	cin >> N;

	for (unsigned long long i = 1; i < N; i++) {
		sol += i*N + i;
	}
	cout << sol << endl;

	return 0;
}