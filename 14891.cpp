#include <iostream>
#include <memory.h>
#include <string>
using namespace std;

string gear[6] = { "", };
bool moveFlag[6];
int moveDir[6];

void lotation() {
	string tmp;
	for (int i = 1; i <= 4; i++) {
		if (moveFlag[i]) {
			if (moveDir[i] == 1) { // �ð����
				tmp = gear[i][7] + gear[i].substr(0, 7);
			}
			else { // �ݽð����
				tmp = gear[i].substr(1, 7) + gear[i][0];
			}
			gear[i] = tmp;
		}
	}

	return;
}

void process(int now, int move) {
	moveFlag[now] = true;
	moveDir[now] = move;
	int tmp = now;
	int next = now - 1;
	while (next >= 1 && gear[tmp][6] != gear[next][2]) { // ���� ��� �̵�
		moveFlag[next] = true;
		moveDir[next] = (moveDir[tmp] * (-1));
		tmp--;
		next--;
	}
	tmp = now;
	next = now + 1;
	while (next <= 4 && gear[tmp][2] != gear[next][6]) { // ������ ��� �̵�
		moveFlag[next] = true;
		moveDir[next] = (moveDir[tmp] * (-1));
		tmp++;
		next++;
	}

	return;
}

int main() {
	int K, start, move; 
	for (int i = 1; i <= 4; i++) {
		cin >> gear[i];
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> start >> move;
		memset(moveFlag, false, sizeof(moveFlag));
		process(start, move);
		lotation();
	}

	int sol = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i + 1][0] == '1')
			sol += (1 << i);
	}
	cout << sol << endl;

	return 0;
}