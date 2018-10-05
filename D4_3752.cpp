#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int process() {
	int N;
	cin >> N;

	vector<int> v;
	v.push_back(0);
	int temp, size;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		size = v.size();
		for (int j = 0; j < size; j++) {
			v.push_back(v[j] + temp);
		}
	}

	sort(v.begin(), v.end());
	size = v.size();
	int sol = 1;
	for (int i = 0; i < size - 1; i++) {
		if (v[i] != v[i + 1])
			sol++;
	}
	return sol;
}

int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cout << "#" << i << " " << process() << endl;
	}
	return 0;
}