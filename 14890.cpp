#include <iostream>
#include <algorithm>
using namespace std;

int N, L, sol;
int map[102][102];

int main() {
	sol = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int now, len;
	bool flag;
	for (int i = 0; i < N; i++) {
		now = map[i][0];
		len = 1;
		flag = true;
		for (int j = 1; j < N; j++) { // row
			if (now == map[i][j]) {
				len++;
			}
			else if (abs(now - map[i][j]) > 1) {
				flag = false;
				break;
			}
			else {
				if (now - 1 == map[i][j]) { // ÇÑÄ­ °¨¼Ò
					len = 1;
					j++;
					for (int k = 1; k < L && j < N; k++, j++) {
						if (now - 1 != map[i][j]) {
							break;
						}
						len++;
					}
					if(L == 1 || map[i][j] != map[i][j - 1]) {
						j--;
					}
					if (L == 1 && map[i][j] < map[i][j + 1]) {
						len = 0;
					}
				}
				if (len < L) {
					flag = false;
					break;
				}
				now = map[i][j];
				len = 1;
			}
		}
		if (flag) {
			sol++;
		}
	}

	for (int i = 0; i < N; i++) {
		now = map[0][i];
		len = 1;
		flag = true;
		for (int j = 1; j < N; j++) { // col
			if (now == map[j][i]) {
				len++;
			}
			else if (abs(now - map[j][i]) > 1) {
				flag = false;
				break;
			}
			else {
				if (now - 1 == map[j][i]) { // ÇÑÄ­ °¨¼Ò
					len = 1;
					j++;
					for (int k = 1; k < L && j < N; k++, j++) {
						if (now - 1 != map[j][i]) {
							break;
						}
						len++;
					}
					if (L == 1 || map[j][i] != map[j - 1][i]) {
						j--;
					}
					if (L == 1 && map[j][i] < map[j + 1][i]) {
						len = 0;
					}
				}
				if (len < L) {
					flag = false;
					break;
				}
				now = map[j][i];
				len = 1;
			}
		}
		if (flag) {
			sol++;
		}
	}
	cout << sol << endl;

	return 0;
}