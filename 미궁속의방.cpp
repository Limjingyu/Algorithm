#include <iostream>
#include <memory.h>
using namespace std;

unsigned long long int Answer;
int A[100002], B[100002];
int AA[100002], BB[100002];
int tempA[100002], tempB[100002];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K;
		cin >> N >> K;

		int now = 1;
		Answer = now;
		memset(A, 0, sizeof(int) * 10002);
		memset(B, 0, sizeof(int) * 10002);
		memset(tempA, 0, sizeof(int) * 10002);
		memset(tempB, 0, sizeof(int) * 10002);
		A[1] = B[1] = 1;
		for (int i = 1; i < N; i++) {
			if (i % 2 == 1) {
				tempA[i] = 1;
				A[i + 1] = A[i] + 1;
				tempB[i] = i * 2;
				B[i + 1] = B[i] + i * 2;
			}
			else {
				tempA[i] = i * 2;
				A[i + 1] = A[i] + i * 2;
				tempB[i] = 1;
				B[i + 1] = B[i] + 1;
			}
		}

		memset(AA, 0, sizeof(int) * 10002);
		memset(BB, 0, sizeof(int) * 10002);
		AA[1] = B[N]; BB[1] = A[N];
		for (int i = 1; i < N; i++) {
			AA[i + 1] = AA[i] + tempA[N - i];
			BB[i + 1] = BB[i] + tempB[N - i];
		}
		char ch;
		int a = 1, b = 1;
		for (int i = 0; i < K; i++) {
			cin >> ch;
			if (ch == 'U') {
				a--;
			}
			else if (ch == 'D') {
				a++;
			}
			else if (ch == 'L') {
				b--;
			}
			else {
				b++;
			}

			if (a + b - 1 <= N) {
				int k = a + b - 1;
				if ((a + b) % 2 == 0) {
					now = B[k];
					now += b - 1;
				}
				else {
					now = A[k];
					now += a - 1;
				}
			}
			else {
				int k = a + b - 5;
				if ((a + b) % 2 == 1) {
					now = BB[k];
					now += N - b;
				}
				else {
					now = AA[k];
					now += N - a;
				}
			}
			Answer += now;
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}