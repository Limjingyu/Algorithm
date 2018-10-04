#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> num;
vector<int>::iterator iter;
vector<long long> sol;

void init() {
	string input;
	cin >> N >> K >> input;
	int len = input.length();
	if(!num.empty()) num.clear();
	for (int i = 0; i < len; i++) {
		if ((int)input[i] - 'A' >= 0) {
			num.push_back(input[i] - 'A' + 10);
		}
		else {
			num.push_back(input[i] - '0');
		}
	}
	if (!sol.empty()) sol.clear();

	return;
}

void process() {
	int n = N / 4, tmp, j, sizee;
	long long number, s;
	bool flag;
	while (n > 0) {
		for (int i = 1; i <= 4; i++) {
			tmp = N / 4;
			j = (tmp * i) - 1;
			number = 0;
			s = 1;
			while (tmp > 0) {
				number += (num[j] * s);
				s *= 16;
				j--;
				tmp--;
			}
			flag = false;
			sizee = sol.size();
			for (int i = 0; i < sizee; i++) {
				if (sol[i] == number) {
					flag = true;
					break;
				}
			}
			if(!flag) {
				sol.push_back(number);
			}
		}
		tmp = num[N - 1];
		iter = num.begin();
		num.insert(iter, tmp);
		n--;
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		process();
		sort(sol.begin(), sol.end());
		reverse(sol.begin(), sol.end());
		cout << "#" << t << " " << sol[K - 1] << endl;
	}

	return 0;
}