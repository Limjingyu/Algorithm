#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, M;
	vector<string> dd, bb, sol;
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		dd.push_back(str);
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		bb.push_back(str);
	}
	sort(dd.begin(), dd.end());
	sort(bb.begin(), bb.end());

	int num_dd = 0, num_bb = 0;
	while (1) {
		if (dd[num_dd].compare(bb[num_bb]) == 0) { // 같을 때 
			sol.push_back(dd[num_dd]);
			num_dd++;
			num_bb++;
		} 
		else if (dd[num_dd].compare(bb[num_bb]) < 0) { // dd가 앞일 때 
			num_dd++;
		} 
		else if (dd[num_dd].compare(bb[num_bb]) > 0) { // dd가 뒤일 때 
			num_bb++;
		}
		if (num_dd >= N || num_bb >= M) break;
	}

	cout << sol.size() << endl;
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << endl;
	}

	return 0;
}