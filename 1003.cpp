#include <iostream>
using namespace std;

int num0, num1;

int fibonacci(int n) {
	if (n == 0) {
		num0++;
		return 0;
	}
	else if (n == 1) {
		num1++;
		return 1;
	}
	else {
		return (fibonacci(n - 1) + fibonacci(n - 2));
	}
}

int main() {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		num0 = num1 = 0;
		fibonacci(N);
		cout << num0 << " " << num1 << endl;
	}
	return 0;
}