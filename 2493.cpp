#include <iostream>
using namespace std;

unsigned int H[500002] = { 0, };
unsigned int now_max[500002] = { 0, };

int main(int argc, char** argv) {

	int N, top;
	unsigned int maxx = 0;
	cin >> N;
	for (top = 1; top <= N; top++) {
		cin >> H[top];
		if (maxx < H[top]) {
			maxx = H[top];
			now_max[top] = maxx;
		}
		else
			now_max[top] = now_max[top - 1];
	}

	for (int i = 1; i <= N; i++) {
		if (now_max[i - 1] < H[i]) {
			cout << "0 ";
			continue;
		}
		top = i - 1;
		while (top > 0) {
			if (H[top] >= H[i]){
				cout << top << " ";
				break;
			}
			top--;
		}
	}
	return 0;
}