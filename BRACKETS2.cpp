#include <iostream>
#include <string>
using namespace std;

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		string str;
		char stack[10000];
		int top = -1;
		cin >> str;
		int len = str.length();
		bool flag = true;
		for (int j = 0; j < len; j++) {
			if (str[j] == '(' || str[j] == '[' || str[j] == '{')
				stack[++top] = str[j];
			else {
				if ((str[j] == ')' && stack[top] == '(') 
					|| (str[j] == ']' && stack[top] == '[')
					|| (str[j] == '}' && stack[top] == '{')) {
					top--;
				}
				else {
					flag = false;
					break;
				}
			}
		}
		if (flag && top == -1) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}