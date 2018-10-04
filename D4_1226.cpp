#include <iostream>
#include <string>
using namespace std;

string input[16];
bool visited[16][16];
int endX, endY;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool dfs(int x, int y) {
	visited[x][y] = true;

	if (x == endX && y == endY)
		return true;

	for (int i = 0; i < 4; i++) {
		if (input[x + dx[i]][y + dy[i]] != '1' && !visited[x + dx[i]][y + dy[i]]) {
			if(dfs(x + dx[i], y + dy[i]))
				return true;
		}
	}

	return false;
}

int process() {
	int startX, startY;
	for (int i = 0; i < 16; i++) {
		cin >> input[i];
		for (int j = 0; j < 16; j++) {
			if (input[i][j] == '2') {
				startX = i;
				startY = j;
			}
			else if (input[i][j] == '3') {
				endX = i;
				endY = j;
			}
			visited[i][j] = false;
		}
	}

	if (dfs(startX, startY))
		return 1;
	else
		return 0;
}

int main() {
	int tc;
	for (int i = 1; i <= 10; i++) {
		cin >> tc;
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}