#include <iostream>
using namespace std;

int T, N;
int dpZero[41];
int dpOne[41];

void fib01num() {
	dpZero[0] = 1; dpOne[0] = 0;
	dpZero[1] = 0; dpOne[1] = 1;

	for (int i = 2; i <= N; i++) {
		dpZero[i] = dpZero[i - 1] + dpZero[i - 2];
		dpOne[i] = dpOne[i - 1] + dpOne[i - 2];
	}
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		fib01num();
		cout << dpZero[N] << " " << dpOne[N] << '\n';
	}
}