#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<string> str[51];
	string s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		str[s.length()].push_back(s);
	}
	for (int i = 1; i < 51; i++) {
		sort(str[i].begin(), str[i].end());
		int len = str[i].size();
		s = "";
		for (int j = 0; j < len; j++) {
			if (s == str[i][j]) continue;
			else s = str[i][j];
			cout << str[i][j] << endl;
		}
	}


	return 0;
}