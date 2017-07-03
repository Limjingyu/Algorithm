//#include <iostream>
//#include <memory.h>
//using namespace std;
//
//int Answer;
//char str[1000002];
//int stack[1000002];
//int N, sp, k, maxx;
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		for (int i = 0; i < 1000002; i++) {
//			str[i] = 'a';
//			stack[i] = 0;
//		}
//		cin >> str;
//
//		Answer = 0;
//		N = sp = 0;
//		k = 1;
//		while (str[N] != '\0')
//		{
//			if (str[N] == '(') {
//				stack[sp] = 1;
//				sp++;
//			}
//			else if (str[N] == ')') {
//				if (stack[sp - 1] == 1) {
//					sp--;
//					k = 1;
//					while (k <= N) {
//						if (str[N-k] == '(') {
//							str[N] = str[N - k] = 'b';
//							break;
//						}
//						k++;
//					}
//				}
//				else {
//					sp = 0;
//				}
//			}
//			else if (str[N] == '{') {
//				stack[sp] = 2;
//				sp++;
//			}	
//			else if (str[N] == '}') {
//				if (stack[sp - 1] == 2) {
//					sp--;
//					k = 1;
//					while (k <= N) {
//						if (str[N - k] == '{') {
//							str[N] = str[N - k] = 'b';
//							break;
//						}
//						k++;
//					}
//				}
//				else {
//					sp = 0;
//				}
//			}
//			else if (str[N] == '[') {
//				stack[sp] = 3;
//				sp++;
//			}
//			else if (str[N] == ']') {
//				if (stack[sp - 1] == 3) {
//					sp--;
//					k = 1;
//					while (k <= N) {
//						if (str[N - k] == '[') {
//							str[N] = str[N - k] = 'b';
//							break;
//						}
//						k++;
//					}
//				}
//				else {
//					sp = 0;
//				}
//			}
//			N++;
//		}
//
//		for (int i = 0; i < N; i++) {
//			maxx = 0;
//			while (str[i] == 'b') {
//				maxx++;
//				i++;
//			}
//			if (Answer < maxx) Answer = maxx;
//		}
//
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;
//}