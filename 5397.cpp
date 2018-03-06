#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	int N, len;
	cin >> N;
	string str; 
	list<char> li;
	list<char> ::iterator p, temp;
	for (int i = 0; i < N; i++) {
		cin >> str;
		li.clear();
		p = li.begin();
		len = str.length();
		for (int j = 0; j < len; j++) {
			if (str[j] == '<') {
				if (p != li.begin()) 
					p--;
			}
			else if (str[j] == '>') {
				if (p != li.end())
					p++;
			}
			else if (str[j] == '-') {
				if (!li.empty() && p != li.begin()) {
					temp = --p;
					p++;
					li.erase(temp);
				}
			}
			else {
				li.insert(p, str[j]);
			}
		}
		for (p = li.begin(); p != li.end(); p++) 
			cout << *p;
		cout << endl;
	}
	return 0;
}
