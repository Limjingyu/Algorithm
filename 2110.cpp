#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, C;
	cin >> N >> C;

	int temp;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int left = 1, right = v[N - 1] - v[0];
	int mid, cnt, start, ret = -1;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 1;
		start = v[0];

		for (int i = 1; i < N; i++){
			if (v[i] - start >= mid){
				cnt++;
				start = v[i];
			}
		}
		if (cnt >= C) {
			ret = mid;
			left = mid + 1;
		}
		else 
			right = mid - 1;
	}

	cout << ret << endl;
	return 0;
}