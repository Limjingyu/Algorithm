#include <iostream>
#include <memory.h>
using namespace std;

int gear[6][10] = { 0, };
bool moveFlag[6];
int moveDir[6];

void lotation() {
	int tmp[10];
	for (int i = 1; i <= 4; i++) {
		if (moveFlag[i]) {
			if (moveDir[i] == 1) { // 시계방향
				tmp[0] = gear[i][7];
				for (int j = 0; j < 7; j++) {
					tmp[j + 1] = gear[i][j];
				}
			}
			else { // 반시계방향
				for (int j = 0; j < 7; j++) {
					tmp[j] = gear[i][j + 1];
				}
				tmp[7] = gear[i][0];
			}
			for (int j = 0; j < 8; j++) {
				gear[i][j] = tmp[j];
			}
		}
	}

	return;
}

void process(int now, int move) {
	moveFlag[now] = true;
	moveDir[now] = move;
	int tmp = now;
	int next = now - 1;
	while (next >= 1 && gear[tmp][6] != gear[next][2]) { // 왼쪽 톱니 이동
		moveFlag[next] = true;
		moveDir[next] = (moveDir[tmp] * (-1));
		tmp--;
		next--;
	}
	tmp = now;
	next = now + 1;
	while (next <= 4 && gear[tmp][2] != gear[next][6]) { // 오른쪽 톱니 이동
		moveFlag[next] = true;
		moveDir[next] = (moveDir[tmp] * (-1));
		tmp++;
		next++;
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		int K, start, move; 
		cin >> K;
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> gear[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> start >> move;
			memset(moveFlag, false, sizeof(moveFlag));
			process(start, move);
			lotation();
		}
		int sol = 0;
		for (int i = 0; i < 4; i++) {
			if (gear[i + 1][0] == 1)
				sol += (1 << i);
		}
		cout << "#" << t << " " << sol << endl;
	}

	return 0;
}