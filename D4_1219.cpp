#include <iostream>
#include <queue>
using namespace std;

int process() {
	int len;
	cin >> len;

	int s, e;
	int map[2][101] = { 0, };
	for (int i = 0; i < len; i++) {
		cin >> s >> e;
		if (map[0][s] == 0)
			map[0][s] = e;
		else
			map[1][s] = e;
	}

	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int i = q.front();
		q.pop();

		if (map[0][i] == 99 || map[1][i] == 99) {
			return 1;
		}

		if(map[0][i]!= 0)
			q.push(map[0][i]);
		if (map[1][i] != 0)
			q.push(map[1][i]);
	}

	return 0;
}

int main() {
	int tc;
	for (int i = 1; i <= 10; i++) {
		cin >> tc;
		cout << "#" << i << " " << process() << endl;
	}

	return 0;
}