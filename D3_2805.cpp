#include <iostream>
#include <string>
using namespace std;

string input;

int process() {
	int N;
	cin >> N;
	int line = 0, start = N / 2, end = N / 2, sol = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = start; j <= end; j++) {
			sol += input[j] - '0';
		}
		if (line < N / 2) {
			start--; end++;
		}
		else {
			start++; end--;
		}
		line++;
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