#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct Info {
	int id, tk, use;
};

bool comp(Info &a, Info &b) {
	if (a.tk == b.tk) 
		return a.use < b.use;
	return a.tk < b.tk;
}

int N, M, K, A, B, sol;
int timeA[10], timeB[10];
int acceA[10], acceB[10];
queue<Info> queueA;
vector<Info> v;

void init() {
	cin >> N >> M >> K >> A >> B;
	sol = 0;
	for (int i = 1; i <= N; i++) {
		cin >> timeA[i];
		acceA[i] = 0;
	}
	for (int i = 1; i <= M; i++) {
		cin >> timeB[i];
		acceB[i] = 0;
	}
	while (!queueA.empty()) {
		queueA.pop();
	}
	if(!v.empty()) v.clear();
	int tmp;
	for (int i = 1; i <= K; i++) {
		cin >> tmp;
		queueA.push(Info{ i, tmp, 0 });
	}
}

void process() {
	int now_time = 0;
	Info info;
	while (!queueA.empty() || !v.empty()) {
		while (!queueA.empty()) {
			info = queueA.front();
			
			//회원이 온시간 > 현재시간 : continue;
			if (info.tk > now_time)
				break;

			//이용가능한 창구 찾기 : 사용한 A창구 저장 + B사용가능시간 설정(now_time+현재창구작업시간)
			int i;
			for (i = 1; i <= N; i++) {
				if(acceA[i] <= now_time) {
					queueA.pop();
					acceA[i] = now_time + timeA[i];
					info.tk = acceA[i];
					info.use = i;
					v.push_back(info);
					break;
				}
			}
			if (i == N + 1)
				break;
		}

		if(v.size() >= 1) {
			if(v.size() >= 2)
				sort(v.begin(), v.end(), comp);
			while (!v.empty()) {
				if (v[0].tk > now_time)
					break;
				
				//이용가능한 창구 찾기 : 현재B이고, A도 썼을경우? sol += info.id;
				int i;
				for (i = 1; i <= M; i++) {
					if (acceB[i] <= now_time) {
						acceB[i] = now_time + timeB[i];
						if (v[0].use == A && i == B)
							sol += v[0].id;
						v.erase(v.begin());
						break;
					}
				}
				if (i == M + 1)
					break;
			}
		}
		now_time++;
	}
}

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		init();
		process();
		if (sol == 0) sol = -1;
		cout << "#" << t << " " << sol << endl;
	}
	return 0;
}