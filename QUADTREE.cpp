#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	
	if (head == 'b' || head == 'w')
		return string(1,head);

	string upleft = reverse(it);
	string upright = reverse(it);
	string downleft = reverse(it);
	string downright = reverse(it);
	return string("x") + downleft + downright + upleft + upright;
}

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		string str; 
		cin >> str;
		string::iterator it = str.begin();
		cout << reverse(it) << endl;
	}
	return 0;
}