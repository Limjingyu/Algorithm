#include <iostream>
using namespace std;

int N, M;
int map[22][22];
int service_price[22];

void init() {
	for (int k = 1; k <= 21; k++) {
		service_price[k] = k*k + (k - 1)*(k - 1);
	}
	return;
}

void input() {
	int num, tmp;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		num = 0;
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1) {
				num++;
			}
			map[i][j] = num;
		}
	}
	
	return;
}

int process() {
	int sol = 1;
	int s, e, tmp_s, tmp_e, house;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 21; k++) {
				s = j;
				e = j;
				house = 0;
				for (int tmp_i = i - k + 1; tmp_i < i + k; tmp_i++) {
					if (tmp_i >= 1 && tmp_i <= N) {
						if (s < 1) tmp_s = 1;
						else tmp_s = s;
						if (e > N) tmp_e = N;
						else tmp_e = e;
						house += map[tmp_i][tmp_e] - map[tmp_i][tmp_s - 1];
					}
					if (tmp_i < i) {
						s--;
						e++;
					}
					else {
						s++;
						e--;
					}
				}
				if ((house * M) - service_price[k] >= 0) {
					if(sol < house)
						sol = house;
				}
			}
		}
	}

	return sol;
}

int main() {
	int TC;
	cin >> TC;
	init();
	for (int t = 1; t <= TC; t++) {
		input();
		cout << "#" << t << " " << process() << endl;
	}
	return 0;
}