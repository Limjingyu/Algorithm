#include <iostream>
using namespace std;

int input[1000002];

long long process() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	long long sol = 0;
	int maxx = input[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (maxx > input[i]) {
			sol += (maxx - input[i]);
		}
		else {
			maxx = input[i];
		}
	}
	return sol;
}


int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cout << "#" << i << " " << process() << endl;
	}
}