#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N;
bool visited[25][25];
int cnt;
string map[25];

int di[4] = { -1, 1, 0 ,0 };
int dj[4] = { 0, 0, -1, 1 };

void dfs(int i, int j) {
	visited[i][j] = true;
	cnt++;
	int ii, jj;
	for (int k = 0; k < 4; k++) {
		ii = i + di[k];
		jj = j + dj[k];
		if (0 <= ii && ii < N && 0 <= jj && jj < N && map[ii][jj] == '1' && !visited[ii][jj]) {
			dfs(ii, jj);
		}
	}

	return;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	vector<int> sol;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				sol.push_back(cnt);
			}
		}
	}

	int size = sol.size();
	sort(sol.begin(), sol.end());
	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << sol[i] << endl;
	}
}