#include <stdio.h>
#include <malloc.h>

int **map;
int *arr;
int computer, line;
int a, b;
int result = 0;

void find(int p);

int main(void) {
	scanf("%d", &computer);
	scanf("%d", &line);

	map = (int**)malloc(sizeof(int*)*computer);
	for (int k = 0; k < computer; k++) {
		map[k] = (int*)malloc(sizeof(int)*computer);
	}
	arr = (int*)malloc(sizeof(int)*computer);

	for (int k = 0; k < computer; k++) {
		for (int j = 0; j < computer; j++)
			map[k][j] = 0;
	}

	for (int k = 0; k < computer; k++) {
		arr[k] = 0;
	}
	arr[0] = 1;

	for (int k = 0; k < line; k++) {
		scanf("%d %d", &a, &b);
		map[a - 1][b - 1] = 1;
		map[b - 1][a - 1] = 1;
	}

	find(0);

	for (int k = 0; k < computer; k++) {
		if (arr[k] == 1) {
			result += 1;
		}
	}

	printf("%d\n", result - 1);

	for (int k = 0; k < computer; k++) {
		free(map[k]);
	}
	free(map);
	free(arr);
}

void find(int p) {
	for (int k = 0; k < computer; k++) {
		if (map[p][k] != 0 && arr[k] != 1) {
			arr[k] = 1;
			find(k);
		}
	}
}