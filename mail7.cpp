#include <iostream>
#include <string>
using namespace std;

void func(string str) {
	int len = str.length(), top = 0;
	char stack[100];
	for (int i = 0; i <= len; i++) {
		if (str[i] == ' ' || i == len) {
			while (top > 0)
				cout << stack[--top];
			if (i == len) cout << endl;
			else cout << " ";
		}
		else {
			stack[top++] = str[i];
		}
	}
}
int main() {
	string str = "abc 123 apple";
	func(str);
	return 0;
}