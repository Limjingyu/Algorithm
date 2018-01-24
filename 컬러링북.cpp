#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool flag[101][101];

int bfs(int m, int n, int i, int j, vector<vector<int>> picture) {
	int count = 0;
	queue<int> q_x, q_y;
	q_x.push(i); q_y.push(j);
	flag[i][j] = true;
	int x, y;
	while (!q_x.empty()) {
		x = q_x.front();
		y = q_y.front();
		q_x.pop();
		q_y.pop();
		count++;
		if (x - 1 >= 0 && picture[x][y] == picture[x - 1][y] && !flag[x - 1][y]) {
			flag[x - 1][y] = true;
			q_x.push(x - 1); q_y.push(y);
		}
		if (y - 1 >= 0 && picture[x][y] == picture[x][y - 1] && !flag[x][y - 1]) {
			flag[x][y - 1] = true;
			q_x.push(x); q_y.push(y - 1);
		}
		if (x + 1 < m && picture[x][y] == picture[x + 1][y] && !flag[x + 1][y]) {
			flag[x + 1][y] = true;
			q_x.push(x + 1); q_y.push(y);
		}
		if (y + 1 < n && picture[x][y] == picture[x][y + 1] && !flag[x][y + 1]) {
			flag[x][y + 1] = true;
			q_x.push(x); q_y.push(y + 1);
		}
	}
	return count;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i< 101; i++) //초기화
		for (int j = 0; j < 101; j++)
			flag[i][j] = false;

	for (int i = 0; i< m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && !flag[i][j]) {
				number_of_area++;
				max_size_of_one_area = max(bfs(m, n, i, j, picture), max_size_of_one_area);
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}