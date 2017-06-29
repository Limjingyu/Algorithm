#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;

int Answer;
int A[1000000];

int main(int argc, char** argv) {
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		int N, cur = 0, jump, go;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cin >> jump;

		for (int i = 0; i < N - 1; i++) {
			go = cur + jump;
			if (A[i] <= go && A[i + 1] > go) {
				cur = A[i];
				Answer++;
			}
			else if (A[i] > go) {
				Answer = -1;
				break;
			}
		}
		go = cur + jump;
		if (A[N - 1] <= go)
			Answer++;
		else
			Answer = -1;

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}