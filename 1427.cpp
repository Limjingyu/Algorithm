//#include <iostream>
//using namespace std;
//
//int main() {
//	long long N;
//	cin >> N;
//
//	int arr[10] = { 0, };
//	while (N != 0) {
//		arr[N % 10]++;
//		N /= 10;
//	}
//	
//	for(int i = 9; i>=0; i--) {
//		while (arr[i] != 0) {
//			cout << i;
//			arr[i]--;
//		}
//	}
//
//	return 0;
//}