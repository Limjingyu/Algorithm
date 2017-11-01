//#include <iostream>
//#include <memory>
//using namespace std;
//#define MOD 1000000007
//int dp[102];
//
//int func(int N) {
//	if (N <= 1) return 1;
//	int &ret = dp[N];
//	if (ret != -1) return ret;
//
//	return ret = (func(N - 1) + func(N - 2)) % MOD;
//}
//int main() {
//	int C;
//	cin >> C;
//	for (int i = 0; i < C; i++) {
//		int N;
//		cin >> N;
//		memset(dp, -1, sizeof(dp));
//		cout << func(N) << endl;
//	}
//
//	return 0;
//}
//
///* 반복문 사용구조
//int main(void){
//	int Dp[102] = {0, };
//	int n;
//	Dp[0] = 1; Dp[1] = 1;
//
//	scanf("%d", &n);
//
//	for (int i = 2; i <= n; i++)
//	Dp[i] =  (Dp[i - 1] +Dp[i-2])%MOD;
//
//	printf("%d\n", Dp[n] % MOD);
//	return 0;
//}
//
//*/