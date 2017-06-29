#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;

int Answer;
int A[1002][1002];

int main(int argc, char** argv) {
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		
		Answer = 0;
		for (int i = 0; i < 1002; i++) {
			for (int j = 0; j < 1002; j++) {
				A[i][j] = 0;
			}
		}

		int N, go = 1;
		cin >> N;
		
		char str[1001] = "";
		for (int i = 0; i < N; i++) {
			cin >> str;
			cout << str << endl;
			for (int j = 0; j < N; j++) {
				A[i][j] = (int)str[j] - 48;
				cout << A[i][j] << endl;
			}
		}

		for (int i = 0; i < N; ) {
			int j;
			for (j = 0; j < N; ) {
				if (go == 1) { // 오른쪽
					if (A[i][j] == 0)
						j++;
					else if (A[i][j] % 3 == 1) {
						if (A[i][j] / 3 == 0) Answer++;
						if( A[i][j] < 3) A[i][j] += 3;
						i--;
						go = 4;
					}
					else if (A[i][j] % 3 == 2) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						i++;
						go = 3;
					}
				}
				else if (go == 2) { // 왼쪽
					if (A[i][j] == 0)
						j--;
					else if (A[i][j] % 3 == 1) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						i++;
						go = 3;
					}
					else if (A[i][j] % 3 == 2) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						i--;
						go = 4;
					}
				}
				else if (go == 3) { // 아래쪽
					if (A[i][j] == 0)
						i++;
					else if (A[i][j] % 3 == 1) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						j--;
						go = 2;
					}
					else if (A[i][j] % 3 == 2) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						j++;
						go = 1;
					}
				}
				else if (go == 4) { // 위쪽
					if (A[i][j] == 0)
						i--;
					else if (A[i][j] % 3 == 1) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						j++;
						go = 1;
					}
					else if (A[i][j] % 3 == 2) {
						if (A[i][j] / 3 == 0) Answer++;
						if (A[i][j] < 3) A[i][j] += 3;
						j--;
						go = 2;
					}
				}
				if (i < 0 || j < 0 || i >= N || j >= N)
					break;
			}
			if (i < 0 || j < 0 || i >= N || j >= N)
				break;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}