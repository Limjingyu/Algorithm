#include <iostream>
using namespace std;

int N[120];

int main() {
	for (int i = 1; i < 121; i++) {
		cin >> N[i];
	}
	int now = 1;
	for (int i = 1; i <= 15; i++) {
		int up = now;
		now += i;
		for (int j = now; j <= now + i; j++) {
			if (j == now)
				N[j] += N[up];
			else if (j == now + i)
				N[j] += N[up];
			else {
				if (N[up] > N[up + 1]) N[j] += N[up];
				else N[j] += N[up + 1];
				up++;
			}
		}
	}
	cout << now << endl;
	int max = 0;
	for (int i = now-20; i <= 121; i++) {
		if (N[i] > max) max = N[i];
	}
	cout << max << endl;
	return 0;
}