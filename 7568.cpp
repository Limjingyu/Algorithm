#include <iostream>
using namespace std;

typedef struct arr {
	int x, y, num;
}arr;

arr A[52];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i].x >> A[i].y;
		A[i].num = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i].x < A[j].x && A[i].y < A[j].y) {
				A[i].num++;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		cout << A[i].num << " ";
	}
	cout << A[N-1].num << endl;

	return 0;
}