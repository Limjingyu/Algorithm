#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

bool map[102][102];
int end_x, end_y;
vector<int> dist;

void go() {
	int tmp;
	for (int i = dist.size() - 1; i >= 0; i--) {
		tmp = (dist[i] + 1) % 4;
		end_x += dx[tmp];
		end_y += dy[tmp];
		map[end_x][end_y] = true;
		
		dist.push_back(tmp);
	}
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		dist.clear();
		map[x][y] = true;
		end_x = x + dx[d];
		end_y = y + dy[d];
		map[end_x][end_y] = true;
		dist.push_back(d);
		
		for (int j = 1; j <= g; j++) {
			go();
		}
	}

	int sol = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				sol++;
			}
		}
	}
	cout << sol << endl;
	
	return 0;
}