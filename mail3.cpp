#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n;
vector<string> result;

void func(string str, int open, int close) {
	if (str.length() == n * 2) {
		result.push_back(str);
		return;
	}
	if (open < n)
		func(str + "(", open + 1, close);
	if (close < open)
		func(str + ")", open, close + 1);
}
int main() {
	cin >> n;
	func("", 0, 0);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}