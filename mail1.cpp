//���� �迭(int array)�� �־����� ���� ū �̾����� ���ҵ��� ���� ���Ͻÿ�. ��, �ð����⵵�� O(N)
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1002], dp[1002], N, sol;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	dp[0] = arr[0];
	for (int i = 1; i < N; i++)
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	for (int i = 1; i < N; i++)
		sol = max(dp[i - 1], dp[i]);

	cout << sol << endl;
	return 0;
}