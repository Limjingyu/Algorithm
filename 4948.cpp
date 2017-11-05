#include <iostream>
using namespace std;

int map[250000];

int main() {
	for (int i = 2; i < 250000; i++) {
		int flag = 0;
		for (int j = i; j < 250000; j += i) {
			if(map[j] == 0 && flag == 0) flag = 1;
			else if(flag == 1) map[j] = 1;
		}
	}

	int n;
	do {
		cin >> n;
		if (n == 0) break;
		if (n == 1) {
			cout << "1" << endl;
			continue;
		}
		int sol = 0;
		for (int i = n+1; i < n * 2; i++) {
			if (map[i] == 0) sol++;
		}
		cout << sol << endl;
	} while (true);

	return 0;
}