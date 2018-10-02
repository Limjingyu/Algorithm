#include <iostream>
#include <string>
using namespace std;

int changeChartoInt(char c) {
	if ('A' <= c && c <= 'Z')
		return c - 'A';
	else if ('a' <= c && c <= 'z')
		return c - 'a' + 26;
	else if ('0' <= c && c <= '9')
		return c - '0' + 52;
	else if (c == '+')
		return 62;
	else
		return 63;
}
string process() {
	string input;
	cin >> input;
	
	int len = input.length();
	string sol;

	for (int i = 0; i < len; i += 4) {
		int ch[4] = { 0, };
		for (int j = i; j < i + 4; j++) {
			ch[j - i] = changeChartoInt(input[j]);
		}
		sol += (char)(ch[0] << 2) + (char)(ch[1] >> 4);
		sol += (char)(ch[1] << 4) + (char)(ch[2] >> 2);
		sol += (char)(ch[2] << 6) + (char)(ch[3]);
	}

	return sol;
}
int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}