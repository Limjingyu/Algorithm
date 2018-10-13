#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int i, j;
};
int N, M, sol;
vector<point> house, chicken;
int houseNum, chickenNum;
bool used[15];

int checkDir() {
	int minn, ret = 0;
	for (int i = 0; i < houseNum; i++) {
		minn = 101;
		for (int j = 0; j < chickenNum; j++) {
			if(used[j])
				minn = min(minn, abs(house[i].i - chicken[j].i) + abs(house[i].j - chicken[j].j));
		}
		ret += minn;
	}

	return ret;
}

void dfs(int ii, int depth) {
	if (depth == M) {
		sol = min(sol, checkDir());
	}

	for (int i = ii; i < chickenNum; i++) {
		if (!used[i]) {
			used[i] = true;
			dfs(i + 1, depth + 1);
			used[i] = false;
		}
	}

}

int main() {
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp == 1) {
				house.push_back(point{ i,j });
			}
			else if (tmp == 2) {
				chicken.push_back(point{ i,j });
			}
		}
	}
	houseNum = house.size();
	chickenNum = chicken.size();
	sol = 987654321;
	dfs(0, 0);

	cout << sol << endl;
	return 0;
}