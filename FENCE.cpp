#include <iostream>
using namespace std;

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))

int fence[20002];

int func(int start, int end) {
	
	if (start == end) return fence[start];
	
	int mid = (start + end) / 2;
	
	int ret = Max(func(start, mid), func(mid+1, end));
	
	int lo = mid, hi = mid + 1;
	int len = Min(fence[lo], fence[hi]);

	ret = Max(ret, len * 2);

	while (start < lo || hi < end) {
		if (hi< end && (start == lo || fence[lo - 1] < fence[hi + 1])) {
			hi++;
			len = Min(len, fence[hi]);
		}
		else {
			lo--;
			len = Min(len, fence[lo]);
		}

		ret = Max(ret, len*(hi - lo + 1));
	}
	return ret;
}
int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> fence[j];
		}
		fence[N] = 0;

		cout << func(0, N) << endl;
	}
	return 0;
}