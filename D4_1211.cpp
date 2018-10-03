#include <iostream>
#include <algorithm>
using namespace std;

int map[102][102];

int process() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> map[i][j];
		}
	}

	int ii, sol = 999999;
	for (int i = 0; i < 100; i++) {
		if (map[0][i] == 1) {
			int point = i;
			int count = 100;
			for (int j = 1; j < 100; j++) {
				if (map[j][point - 1] == 1) {
					while (map[j][point - 1] == 1) {
						point--;
						count++;
					}
				}
				else if (map[j][point + 1] == 1) {
					while (map[j][point + 1] == 1) {
						point++;
						count++;
					}
				}
			}
			cout << i << "  : " << count << endl;
			if (count < sol) {
				sol = count;
				ii = i;
			}
		}
	}

	return ii;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		int tc;
		cin >> tc;
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}