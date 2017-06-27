#include <cstdio>
#include <iostream>
using namespace std;
int N, sol[1000003];
int main(int argc, char** argv) {
	cin >> N;

	sol[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		sol[i] = sol[i - 1] + 1;
		if (i % 2 == 0 && sol[i] > sol[i / 2] + 1)
			sol[i] = sol[i / 2] + 1;
		if (i % 3 == 0 && sol[i] > sol[i / 3] + 1)
			sol[i] = sol[i / 3] + 1;
	}

	cout << sol[N];

	return 0;
}