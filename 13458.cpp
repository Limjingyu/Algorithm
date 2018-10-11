#include <iostream>
using namespace std;

int input[1000002];

int main() {
	int N, B, C, tmp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	cin >> B >> C;
	unsigned long long sol = N;
	for (int i = 0; i < N; i++) {
		if (input[i] - B > 0) {
			tmp = (input[i] - B) / C;
			if ((input[i] - B) % C > 0)
				tmp++;
			sol += tmp;
		}
	}
	cout << sol << endl;

	return 0;
}