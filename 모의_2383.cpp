//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <memory>
//using namespace std;
//
//struct point {
//	int i, j;
//};
//
//int people_num, sol;
//vector<point> people;
//bool people_used_s[11];
//point s1, s2;
//int depth_s1, depth_s2;
//vector<int> v_s1, v_s2;
//int used[2002];
//
//void init() {
//	int N, tmp;
//	cin >> N;
//	depth_s1 = depth_s2 = 0;
//	people.clear();
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> tmp;
//			if (tmp == 1) {
//				people.push_back(point{ i,j });
//			}
//			else if (tmp > 1) {
//				if (depth_s1 == 0) {
//					s1.i = i;
//					s1.j = j;
//					depth_s1 = tmp;
//				}
//				else {
//					s2.i = i;
//					s2.j = j;
//					depth_s2 = tmp;
//				}
//			}
//		}
//	}
//	people_num = people.size();
//	sol = 3000;
//
//	return;
//}
//
//void setting() {
//	for (int i = 0; i < people_num; i++) {
//		if (people_used_s[i]) {
//			v_s1.push_back((abs(people[i].i - s1.i) + abs(people[i].j - s1.j) + 1));
//		}
//		else {
//			v_s2.push_back((abs(people[i].i - s2.i) + abs(people[i].j - s2.j) + 1));
//		}
//	}
//	sort(v_s1.begin(), v_s1.end());
//	sort(v_s2.begin(), v_s2.end());
//}
//
//void checkTime() {
//	int s1_time = 0, s2_time = 0;
//	int use = 0;
//	if(v_s1.size() > 0) s1_time = v_s1[0];
//	memset(used, 0, sizeof(used));
//	while(!v_s1.empty()) {
//		if (use < 3 && s1_time >= v_s1[0]) {
//			use++;
//			used[s1_time + depth_s1]++;
//			v_s1.erase(v_s1.begin());
//		}
//		else {
//			s1_time++;
//			use -= used[s1_time];
//		}
//	}
//
//	use = 0;
//	if (v_s2.size() > 0) s2_time = v_s2[0];
//	memset(used, 0, sizeof(used));
//	while (!v_s2.empty()) {
//		if (use < 3 && s2_time >= v_s2[0]) {
//			use++;
//			used[s2_time + depth_s2]++;
//			v_s2.erase(v_s2.begin());
//		}
//		else {
//			s2_time++;
//			use -= used[s2_time];
//		}
//	}
//	sol = min(sol, max(s1_time + depth_s1, s2_time + depth_s2));
//	return;
//}
//
//void dfs(int now) {
//	if (now == people_num + 1) {
//		setting();
//		checkTime();
//		return;
//	}
//
//	//for (int i = 0; i < 2; i++) {
//	//	people_used_s[now] = i;
//	//	dfs(now + 1);
//	//}
//	for (int i = now; i <= people_num; i++) {
//		people_used_s[i] = true;
//		dfs(i + 1);
//		people_used_s[i] = false;
//	}
//
//	return;
//}
//
//int main() {
//	int TC;
//	cin >> TC;
//	for (int t = 1; t <= TC; t++) {
//		init();
//		dfs(0);
//		cout << "#" << t << " " << sol << endl;
//	}
//	return 0;
//}