#include <iostream>
using namespace std;

int sol1(int n) {
	int sum = 0;
	int x = 1;
	int y = 2;
	int z;
	while (x <= n) {
		if (x % 2 == 0) sum += x;
		z = x + y;
		x = y;
		y = z;
	}
	return sum;
}
int sol2(int n) {
	int preValue = 0;
	int temp = 0;
	int curValue = 2;
	int sum = 0;

	while (curValue < n) {
		sum += curValue;
		temp = curValue;
		curValue = curValue * 4 + preValue;
		preValue = temp;
	}

	return sum;
}
int main() {
	int n;
	cin >> n;
	
	cout << sol1(n) << endl;
	cout << sol2(n) << endl;
	
	return 0;
}