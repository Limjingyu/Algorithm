/*
무선충전
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct bc {
	int i, j;
	int C;
	int P;
};

bool comp(bc &a, bc &b) {
	return a.P > b.P;
}

int di[5] = { 0, -1, 0, 1, 0 };
int dj[5] = { 0, 0, 1, 0, -1 };

int process() {
	int M, A;
	int moveA[102], moveB[102];
	vector<bc> BC;
	cin >> M >> A;
	for (int i = 0; i < M; i++) {
		cin >> moveA[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> moveB[i];
	}
	bc tmp;
	for (int i = 0; i < A; i++) {
		cin >> tmp.j >> tmp.i >> tmp.C >> tmp.P;
		BC.push_back(tmp);
	}
	sort(BC.begin(), BC.end(), comp);
	for (int i = 0; i < A; i++) {
		cout << BC[i].P << endl;
	}
	bc userA, userB;
	userA.i = 1; userA.j = 1;
	userB.i = 10; userB.j = 10;
	bool useA[12], useB[12];
	bool flagA, flagB;
	int cnt, sol = 0;
	for (int j = 0; j <= M; j++) {
		for (int i = 0; i < A; i++) {
			useA[i] = false;
			if (abs(userA.i - BC[i].i) + abs(userA.j - BC[i].j) <= BC[i].C) {
				useA[i] = true;
			}
		}
		for (int i = 0; i < A; i++) {
			useB[i] = false;
			if (abs(userB.i - BC[i].i) + abs(userB.j - BC[i].j) <= BC[i].C) {
				useB[i] = true;
			}
		}
		cnt = 0;
		flagA = false;
		flagB = false;
		for (int i = 0; i < A; i++) {
			if(useA[i] && useB[i]) {
				sol += BC[i].P;
				cnt++;
			}
			else if (useA[i] && !flagA) {
				flagA = true;
				sol += BC[i].P; 
				cnt++;
			}
			else if (useB[i] && !flagB) {
				flagB = true;
				sol += BC[i].P; 
				cnt++;
			}
			if (cnt == 2) break;
		}
		if (j == M) break;
		userA.i += di[moveA[j]];
		userA.j += dj[moveA[j]];
		userB.i += di[moveB[j]];
		userB.j += dj[moveB[j]];
	}

	return sol;
}

int main() {
	int TC;
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}