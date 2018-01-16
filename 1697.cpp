#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];

int main(void) {
	int N, K;
	cin >> N >> K;

	int n, cnt;
	queue<int> q_n, q_cnt;
	q_n.push(N); q_cnt.push(0);
	while (!q_n.empty()) {
		n = q_n.front();
		cnt = q_cnt.front();
		q_n.pop();
		q_cnt.pop();
		if (n < 0 || n > 100000) continue;
		if (visited[n]) continue;
		visited[n] = true;
		if (n == K) break;
		q_n.push(n * 2); q_cnt.push(cnt + 1);
		q_n.push(n + 1); q_cnt.push(cnt + 1);
		q_n.push(n - 1); q_cnt.push(cnt + 1);
	}

	cout << cnt << endl;
	return 0;
}