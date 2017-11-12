#include <iostream>
using namespace std;

int N, pa;
int ch_num[51] = { 0, }, my_pa[51] = { 0, };
bool flag[51];

void func(int del) {
	flag[del] = true;
	ch_num[my_pa[del]]--;
	if (ch_num[del] == 0) return;

	for (int i = 0; i < N; i++) {
		if (my_pa[i] == del) {
			func(i);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> pa;
		if (pa != -1)
			ch_num[pa]++;
		my_pa[i] = pa;
	}
	int del;
	cin >> del;
	func(del);

	int sol = 0;
	for (int i = 0; i < N; i++) {
		if (ch_num[i] == 0 && !(flag[i]))
			sol++;
		
	}
	cout << sol << endl;
	return 0;
}
// 13 -1 0 0 0 1 1 2 2 2 3 3 6 8
// 13 2 0 0 0 1 1 -1 2 2 3 3 6 8

// 11 -1 0 0 0 1 1 2 3 6 6 6

// 13 2 7 7 2 5 7 10 -1 1 1 5 4 5