#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Info {
	int i, j;
	int cost;
};

int map[12][12];
vector<Info> v;
int len;
int sol = 987654321;

void dfs(Info now[2], int ii, bool flag) {
	for (int i = ii + 1; i < len; i++) {
		if (!flag) {
			if ((abs(v[i].i - now[0].i) + abs(v[i].j - now[0].j)) > 2) {
				now[1].i = v[i].i;
				now[1].j = v[i].j;
				now[1].cost = v[i].cost + now[0].cost;
				dfs(now, i, !flag);
			}
		}
		else {
			if ((abs(v[i].i - now[0].i) + abs(v[i].j - now[0].j)) > 2 &&
				(abs(v[i].i - now[1].i) + abs(v[i].j - now[1].j)) > 2) {
				if (sol > v[i].cost + now[1].cost) {
					sol = v[i].cost + now[1].cost;
				}
			}
		}
	}

	return;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	Info tmp;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			tmp.i = i;
			tmp.j = j;
			tmp.cost = map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1];
			v.push_back(tmp);
		}
	}

	len = v.size();
	Info now[2];
	for (int i = 0; i < len; i++) {
		now[0] = v[i];
		dfs(now, i, false);
	}

	cout << sol << endl;
	return 0;
}