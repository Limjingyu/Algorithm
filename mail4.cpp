#include <iostream>
#include <string>
using namespace std;

int main() {
	int input, revert = 0;
	bool flag;
	cin >> input;

	if (input < 0 || (input % 10 == 0 && input != 0))
		flag = false;
	else {
		while (input > revert) {
			revert = revert * 10 + input % 10;
			input /= 10;
		}
		flag = (input == revert) || (input == revert / 10);
	}

	string sol;
	sol = flag ? "True" : "False";
	cout << sol << endl;

	return 0;
}