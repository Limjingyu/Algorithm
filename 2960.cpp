#include <iostream>
using namespace std;

char map[1002];

int main() {
	int N, K;
	cin >> N >> K;
	int count = 0, sol = 0;

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (map[j] != 'x') {
				count++;
				map[j] = 'x';
				if (count == K) {
					sol = j;
					i = j = N + 1;
				}
			}
		}
	}

	cout << sol << endl;

	return 0;
}