#include <cstdio>

int a[2001];
bool d[2001][2001];

int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (int i = 1; i < n; i++) {
		d[i][i] = true;
		if (a[i] == a[i + 1]) d[i][i + 1] = true;
		else d[i][i + 1] = false;
	}
	d[n][n] = true;

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i < j - 1; i++) {
			if (d[i + 1][j - 1] && a[i] == a[j]) d[i][j] = true;
			else d[i][j] = false;
		}
	}

	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		if (d[s][e]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}