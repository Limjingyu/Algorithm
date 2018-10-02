///*
//¿ä¸®»ç
//*/
//#include <iostream>
//#include <memory.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N, NN, sol;
//int S[20][20];
//bool food[20];
//
//void init() {
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> S[i][j];
//		}
//	}
//	NN = N / 2;
//	sol = 987654321;
//	memset(food, false, sizeof(food));
//}
//
//void dfs(int ii, int n) {
//	if (n == NN) {
//		vector<int> v1, v2;
//		int len1, len2;
//		int taste1 = 0, taste2 = 0;
//		for (int i = 1; i <= N; i++) {
//			if (food[i]) {
//				len1 = v1.size();
//				for (int j = 0; j < len1; j++) {
//					taste1 += (S[i][v1[j]] + S[v1[j]][i]);
//				}
//				v1.push_back(i);
//			}
//			else {
//				len2 = v2.size();
//				for (int j = 0; j < len2; j++) {
//					taste2 += (S[i][v2[j]] + S[v2[j]][i]);
//				}
//				v2.push_back(i);
//			}
//		}
//		if (sol > abs(taste1 - taste2)) {
//			sol = abs(taste1 - taste2);
//		}
//		return;
//	}
//
//	for (int i = ii + 1; i <= N; i++) {
//		food[i] = true;
//		dfs(i, n + 1);
//		food[i] = false;
//	}
//
//	return;
//}
//
//int main() {
//	int TC;
//	cin >> TC;
//	for (int i = 1; i <= TC; i++) {
//		init();
//		for (int j = 1; j <= NN; j++) {
//			food[j] = true;
//			dfs(j, 1);
//			food[j] = false;
//		}
//		cout << "#" << i << " " << sol<< endl;
//	}
//	return 0;
//}