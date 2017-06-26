//#include <iostream>
//
//using namespace std;
//
//int Answer;
//
//int main(int argc, char** argv)
//{
//	int T, test_case;
//
//	//freopen("input.txt", "r", stdin);
//	cin >> T;
//	for (test_case = 0; test_case < T; test_case++)
//	{
//		int A, B, C, D;
//		Answer = 1;
//
//		cin >> A >> B >> D;
//		C = A - B;
//		
//		Answer += (D - A) / C;
//		if ((D - A) % C > 0) Answer++;
//
//		
//		cout << "Case #" << test_case + 1 << endl;
//		cout << Answer << endl;
//	}
//
//	return 0;
//}