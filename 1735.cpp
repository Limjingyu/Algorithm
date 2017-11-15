#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) return b;
	return gcd(b, a % b);
}
int main() {
	int A1, B1, A2, B2;
	cin >> A1 >> B1 >> A2 >> B2;

	A1 *= B2;
	A2 *= B1;
	A1 += A2;
	B1 *= B2;
	B2 = gcd(A1, B1);
	cout << A1 / B2 << " " << B1 / B2 << endl;
	return 0;
}