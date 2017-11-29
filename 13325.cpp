#include <stdio.h>

int tree[(1 << 22) + 2];

int main() {
	int K;
	scanf("%d", &K);
	int N = 2 << K;
	for (int i = 2; i < N; i++) scanf("%d", &tree[i]);

	long long sol = 0;
	while (N != 2) {
		for (int i = N / 2; i < N; i = i + 2) {
			if ((tree[i] + tree[i * 2]) >(tree[i + 1] + tree[(i + 1) * 2]))
				tree[i + 1] = tree[i] + tree[i * 2] - tree[(i + 1) * 2];
			else
				tree[i] = tree[i + 1] + tree[(i + 1) * 2] - tree[i * 2];
			sol += (tree[i] + tree[i + 1]);
			tree[i] += tree[i * 2];
		}
		N /= 2;
	}

	printf("%d\n", sol);
	return 0;
}