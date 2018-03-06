#include <cstdio>
using namespace std;

int main() {
	int N, level, max;
	long long sol;
	char ch; 
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		level = 0;
		max = 0;
		sol = 1;
		while (ch = getchar() != '\n') {
			if (ch == '[') {
				level++;
				if (level > max) {
					max = level;
					sol *= 2;
				}
			}
			else level--;
		}
		printf("%lld\n", sol);
	}
}