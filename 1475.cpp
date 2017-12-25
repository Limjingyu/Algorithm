#include <iostream>
using namespace std;

int arr[10];
int main() {
	int N;
	cin >> N;
	if (N == 0) N = 1;
	while (N != 0) {
		arr[N % 10]++;
		N /= 10;
	}
	
	arr[6] += arr[9];
	if (arr[6] % 2 == 0) arr[6] /= 2;
	else arr[6] = (arr[6] + 1) / 2;
	arr[9] = 0;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > arr[9]) arr[9] = arr[i];
	}
	cout << arr[9] << endl;
	return 0;
}