#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<pair<int, int>> stc;

int main() {
	string input, boom;
	cin >> input >> boom;

	if (boom.length() == 1) {
		for (int i = 0; i < input.length(); i++)
			if (input[i] == boom[0])
				input[i] = '*';
	}
	else {
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == boom[0]) 
				stc.push(make_pair(i, 0));
			else {
				if (stc.empty()) continue;
				if (input[i] == boom[stc.top().second + 1]) {
					stc.push(make_pair(i, stc.top().second + 1));
					if (stc.top().second + 1 == boom.length()) {
						for (int j = 0; j < boom.length(); j++) {
							input[stc.top().first] = '*';
							stc.pop();
						}
					}
				}
				else 
					while (!stc.empty()) 
						stc.pop();
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < input.length(); i++)
		if (input[i] != '*') {
			cout << input[i];
			flag = true;
		}
	if (flag) cout << endl;
	else cout << "FRULA" << endl;

	return 0;
}