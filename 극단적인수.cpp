#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int K;
		cin >> K;
		Answer = 0;
		
		cout << "Case #" << test_case + 1 << endl;
		if (K == 1) {
			cout << 4 << endl;
		}
		else if (K == 2) {
			cout << 7 << endl;
		}
		else {
			int m = 2, n = K + 1, cnt = 0;
			while (m <= n) {
				cnt++;
				m *= 2;
			}
			while (cnt>0) {
				m /= 2;
				
				n = n % m;
				
				if (n < m/2)
					cout << 4;
				else
					cout << 7;
				cnt--;
			}
			 cout << endl;
		}
		
	}

	return 0;
}