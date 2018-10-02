#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string process() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	if (abs(B - C) > 1) return "impossible";
	else {
		string sol = "";
		if (B == 0 && C == 0) {
			if (A > 0 && D > 0) {
				sol = "impossible";
			}
			else {
				if (A > 0) {
					A++;
					while (A--) sol += "0";
				}
				if (D > 0) {
					D++;
					while (D--) sol += "1";
				}
			}
		}
		else {
			sol = "0";
			while (B > 0 && C > 0) {
				sol += "10";
				B--; C--;
			}
			if (B > C) {
				sol += "1";
				while (A--) sol = "0" + sol;
				while (D--) sol += "1";
			}
			else if (B < C){
				sol = "1" + sol;
				while (A--) sol += "0";
				while (D--) sol = "1" + sol;
			}
			else {
				while (A--) sol += "0"; 
				if (D > 0) {
					string temp = sol.substr(1, sol.length() - 1);
					while (D--) temp = "1" + temp;
					sol = "0" + temp;
				}
			}
		}
		return sol;
	}
}
int main() {
	int TC;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cout << "#" << i << " " << process() << endl;
	}
	return 0;
}