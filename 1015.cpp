#include <iostream>
using namespace std;

int main() {
	int N, A[51], P[51];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int min, now, temp, count=0;
	for (int i = 0; i < N; i++) {
		min = A[0];
		now = 0;
		for (int j = 0; j < N; j++) {
			if (min > A[j]) {
				now = j;
				min = A[j];
			}
		}
		P[now] = count;
		count++;
		A[now] = 1001;

		/*temp = A[i];
		A[i] = A[now];
		A[now] = temp;*/
	}

	for (int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
	cout << endl;
	return 0;
}