#include <iostream>
using namespace std;

int main() {
	int N;
	char map[101][101];
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int row = 0, col = 0;
	bool row_flag, col_flag;
	for (int i = 0; i < N; i++) {
		row_flag = col_flag = true;
		for (int j = 0; j < N - 1; j++) {
			if (row_flag && map[i][j] == '.' && map[i][j + 1] == '.') {
				row++;
				row_flag = false;
			}
			else if (!row_flag && map[i][j] == 'X') {
				row_flag = true;
			}
			if (col_flag && map[j][i] == '.' && map[j + 1][i] == '.') {
				col++;
				col_flag = false;
			}
			else if (!col_flag && map[j][i] == 'X') {
				col_flag = true;
			}
		}
	}
	cout << row << " " << col << endl;

	return 0;
}