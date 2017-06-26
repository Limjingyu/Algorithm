#include <iostream>
#include <memory>
using namespace std;


int Answer;
int N, M, K;
int map[101][101];
int Ai, Bi, Ci;
int P, S, E;

void floyd_warwhall() {
	for (int i = 1; i <= N; i++) {
		for (int j = i + 2; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if ( map[i][j] >= map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		for (int i = 0; i <= 101; i++) {
			for (int j = 0; j <= 101; j++)
				map[i][j] = 10003;
		}
		Answer = 0;
		cin >> N >> M >> K;
		for (int i = 1; i <= M; i++) {
			cin >> Ai >> Bi >> Ci;
			map[Bi][Ai] = map[Ai][Bi] = Ci;
			
		}
		floyd_warwhall();

		cin >> P;
		for (int i = 1; i <= P; i++) {
			cin >> S >> E;
			if (map[S][E] > K) Answer++;
		}
		
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}