#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N, K;
int A[5000000];

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	printf("%d\n", A[K - 1]);
	return 0;
}