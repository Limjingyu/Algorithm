#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define min(a,b) (((a) < (b)) ? (a) : (b))
#define INFINITY 99999999

int m, n;
int man[1000];
int girl[1000];
int arr[1001][1001];

int find(int _man, int _girl);
void quickSort(int arr[], int left, int right);

int main(void) {
	int result = 0;
	memset(arr, -1, sizeof(arr));
	scanf("%d %d", &n, &m);

	if (n >= m) {
		for (int k = 0; k < n; k++)
			scanf("%d", &man[k]);
		for (int k = 0; k < m; k++)
			scanf("%d", &girl[k]);
		quickSort(man, 0, n - 1);
		quickSort(girl, 0, m - 1);
	}
	else {
		for (int k = 0; k < n; k++)
			scanf("%d", &girl[k]);
		for (int k = 0; k < m; k++)
			scanf("%d", &man[k]);
		quickSort(man, 0, m - 1);
		quickSort(girl, 0, n - 1);
		int temp = n;
		n = m;
		m = temp;
	}
	printf("%d", find(0, 0));
}

int find(int _man, int _girl) {
	if (_girl == m) return 0;
	if (_man == n) return INFINITY;
	if (arr[_man][_girl] != -1) return arr[_man][_girl];
	arr[_man][_girl] = min(find(_man + 1, _girl), find(_man + 1, _girl + 1) + abs(man[_man] - girl[_girl]));
	return arr[_man][_girl];
}

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;
	do {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}