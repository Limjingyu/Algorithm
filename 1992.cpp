#include <iostream>
using namespace std;

char arr[64][64];

void func(int x1, int y1, int x2, int y2) {
	char now = arr[y1][x1];
	int flag = 0;
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			if (now != arr[i][j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}

	if (flag == 0)
		cout << now;
	else {
		cout << '(';
		func(x1, y1, (x1 + x2)/2, (y1 + y2)/2);
		func((x1 + x2)/2, y1, x2, (y1 + y2)/2);
		func(x1, (y1 + y2)/2, (x1 + x2)/2, y2);
		func((x1 + x2)/2, (y1 + y2)/2, x2, y2);
		cout << ')';
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	func(0, 0, N, N);

	return 0;
}