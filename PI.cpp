#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define INF 987654321;
string N;
int dp[10002];

int func2(int start, int end) {
	string str = N.substr(start, end - start + 1);

	int len = str.length();

	int i;
	char now = str[0];
	for (i = 1; i < len; i++)
		if (now != str[i])
			break;
	if (i == len) return 1;
	
	for (i = 1; i < len; i++) {
		if (now + 1 == str[i]) {
			now = str[i];
		}
		else break;
	}
	if (i == len) return 2;
	for (i = 1; i < len; i++) {
		if (now - 1 == str[i]) {
			now = str[i];
		}
		else break;
	}
	if (i == len) return 2;

	now = str[0];
	char now2 = str[1];
	for (i = 2; i < len; i++) {
		if (!(i % 2 == 0 && now == str[i] || i % 2 == 1 && now2 == str[i]))
			break;
	}
	if (i == len) return 4;

	now = now2 - now;
	for (i = 2; i < len; i++) {
		if (!(str[i] - str[i - 1] == now)) break;
	}
	if (i == len) return 5;

	return 10;
}

int func(int start) {
	int len = N.length();
	if (start == len) return 0;

	int &ret = dp[start];
	
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 3; i <= 5; i++) {
		if (start+i <= len)
			ret = min(ret, func(start+i) + func2(start, start+i-1));
	}
	return ret;
}

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N;
		int len = N.length();
		for (int j = 0; j <= len; j++)
			dp[j] = -1;

		cout << func(0) << endl;
	}

	return 0;
}