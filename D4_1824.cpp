#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R, C;
string input[22];
bool visited[20][20][4][16];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> input[i];
	}
	memset(visited, false, sizeof(bool) * 20 * 20 * 4 * 16);
}

bool process(int r, int c, int mem, int move) {
	char ch;
	
	while(true) {
		if (visited[r][c][move][mem]) {
			return false;
		}
		visited[r][c][move][mem] = true;
		ch = input[r][c];
		if (ch == '@') {
			return true;
		}
		else if (ch == '<') {
			move = 2;
		}
		else if (ch == '>') {
			move = 3;
		}
		else if (ch == '^') {
			move = 0;
		}
		else if (ch == 'v') {
			move = 1;
		}
		else if (ch == '_') {
			if (mem == 0) move = 3;
			else move = 2;
		}
		else if (ch == '|') {
			if (mem == 0) move = 1;
			else move = 0;
		}
		else if (ch == '?') {
			for (int j = 0; j < 4; j++) {
				r += dx[j];
				c += dy[j];
				if (r < 0) r = R - 1;
				else if (r == R) r = 0;
				if (c < 0) c = C - 1;
				else if (c == C) c = 0;
				if (process(r, c, mem, j)) {
					return true;
				}
			}
		}
		else if (ch == '.') {
			;
		}
		else if (ch == '+') {
			if (mem != 15) mem++;
			else mem = 0;
		}
		else if (ch == '-') {
			if (mem != 0) mem--;
			else mem = 15;
		}
		else {
			mem = ch - '0';
		}

		r += dx[move];
		c += dy[move];
		if (r < 0) r = R - 1;
		else if (r == R) r = 0;
		if (c < 0) c = C - 1;
		else if (c == C) c = 0;
	}

	return false;
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		init();
		cout << "#" << i << " ";
		if (process(0, 0, 0, 3)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}