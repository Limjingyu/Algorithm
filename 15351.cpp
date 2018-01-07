#include<iostream>
#include <stdlib.h>
#include<string>
using namespace std;

int main() {
	int N, len, sol;
	string str = "";
	getline(cin, str);
	N = atoi(str.c_str());
	for (int i = 0; i < N; i++) {
		str="";
		getline(cin, str);
		len = str.length();
		sol = 0;
		for (int j = 0; j < len; j++) {
			if (str[j] == ' ') continue;
			sol += (str[j] - 'A') + 1;
		}
		if (sol == 100) cout << "PERFECT LIFE" << endl;
		else cout << sol << endl;
	}
	return 0;
}