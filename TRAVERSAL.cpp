#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> slice(const vector<int>& vec, int l, int r) {
	return vector<int>(vec.begin() + l, vec.begin() + r);
}

void func(const vector<int>& preorder, const vector<int>& inorder) {
	const int N = preorder.size();
	if (preorder.empty()) return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - N - 1;

	func(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	func(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	
	cout << root << " ";
}
int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int N;
		cin >> N;
		vector<int> preorder;
		int node;
		for (int j = 0; j < N; j++) {
			cin >> node;
			preorder.push_back(node);
		}
		vector<int> inorder;
		for (int j = 0; j < N; j++) {
			cin >> node;
			inorder.push_back(node);
		}
		func(preorder, inorder);
	}
	return 0;
}