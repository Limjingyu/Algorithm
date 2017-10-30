//#include <iostream>
//using namespace std;
//
//bool map[10][10];
//
//int countPair(int n, bool flag[10]) {
//	int firstFree = -1;
//	for (int i = 0; i < n; i++) {
//		if (!flag[i]) {
//			firstFree = i;
//			break;
//		}
//	}
//	if (firstFree == -1) return 1;
//	int ret = 0;
//	for (int i = firstFree + 1; i < n; i++) {
//		if (!flag[i] && map[firstFree][i]) {
//			flag[i] = flag[firstFree] = true;
//			ret += countPair(n, flag);
//			flag[i] = flag[firstFree] = false;
//		}
//	}
//	return ret;
//}
//
//int main() {
//	int C, n, m;
//	int x, y;
//	cin >> C;
//
//	for (int i = 0; i < C; i++) {
//		cin >> n >> m;
//		for (int j = 0; j < n; j++) {
//			for (int k = 0; k < n; k++) {
//				map[j][k] = map[k][j] = false;
//			}
//		}
//		for (int j = 0; j < m; j++) {
//			cin >> x >> y;
//			map[x][y] = map[y][x] = true;
//		}
//
//		bool flag[10] = { false, };
//		cout << countPair(n, flag) << endl;
//	}
//	return 0;
//}