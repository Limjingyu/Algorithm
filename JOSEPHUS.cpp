#include <iostream>
#include <list>
using namespace std;

void josephus(int N, int K) {
	list<int> li;
	for (int i = 1; i <= N; i++) li.push_back(i);

	list<int>::iterator kill = li.begin();
	while (N > 2) {
		kill = li.erase(kill);
		if (kill == li.end()) kill = li.begin();
		N--;
		for (int j = 1; j < K; j++) {
			kill++;
			if (kill == li.end()) kill = li.begin();
		}
	}
	cout << li.front() << " " << li.back() << endl;
}
int main() {
	int C, N, K;
	cin >> C;

	for (int i = 0; i < C; i++) {
		cin >> N >> K;
		josephus(N, K);
	}
	return 0;
}