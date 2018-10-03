#include <iostream>
#include <string>
using namespace std;

int process() {
	int len;
	cin >> len;
	string input;
	cin >> input;

	int row, col;
	int count[4][2] = { 0, };
	for (int i = 0; i < len; i++) {
		if (input[i] == '(') {
			row = 0; col = 0;
		}
		else if (input[i] == ')') {
			row = 0; col = 1;
		}
		else if (input[i] == '[') {
			row = 1; col = 0;
		}
		else if (input[i] == ']') {
			row = 1; col = 1;
		}
		else if (input[i] == '{') {
			row = 2; col = 0;
		}
		else if (input[i] == '}') {
			row = 2; col = 1;
		}
		else if (input[i] == '<') {
			row = 3; col = 0;
		}
		else if (input[i] == '>') {
			row = 3; col = 1;
		}
		count[row][col]++;
	}

	int flag = 1;
	for (int i = 0; i < 4; i++) {
		if (count[i][0] != count[i][1]) {
			flag = 0;
			break;
		}
	}

	return flag;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}