#include <iostream>
#include <string>
#include <set>
using namespace std;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
int input[5][5];
set<string> s;
int sol;

void dfs(int count, int i, int j, string str) {
	if (count == 7) {
		if (s.find(str) == s.end()) {
			s.insert(str);
			sol++;
		}
		return;
	}
	else {
		str += to_string(input[i][j]);
	}
	for (int k = 0; k < 4; k++) {
		if (0 <= i + di[k] && i + di[k] < 4 && 0 <= j + dj[k] && j + dj[k] < 4) {
			dfs(count + 1, i + di[k], j + dj[k], str);
		}
	}
}

void process() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> input[i][j];
		}
	}
	s.clear();
	sol = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dfs(0, i, j, "");
		}
	}
}


int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		process();
		cout << "#" << i << " " << sol << endl;
	}
}