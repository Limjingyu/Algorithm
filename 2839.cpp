#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int sol = 0;
	if (N >= 5) {
		sol = N / 5;
		N %= 5;
	}
	if (N == 0);
	else if ((N == 1 && sol >= 1) || N == 3) sol++;
	else if ((N == 2 && sol >= 2) || (N == 4 && sol >= 1)) sol += 2;
	else sol = -1;

	cout << sol << endl;

	return 0;
}