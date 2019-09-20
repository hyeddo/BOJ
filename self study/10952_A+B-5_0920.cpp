#include <iostream>
using namespace std;

int Sum(int A, int B) {
	int res = A + B;
	return res;
}

int main(){
	int A, B;
	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0) break;
		cout << Sum(A, B) << '\n';
	}
	return 0;
}