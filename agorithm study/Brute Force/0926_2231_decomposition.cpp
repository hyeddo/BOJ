#include <iostream>
using namespace std;

int N;

int decomp(void) {
	int cnt = 1;
	int sum = 0;
	int numCopy, num=0;

	while (1){
		numCopy = num;
		sum = num;

		while (numCopy) {
			sum += numCopy % 10;
			numCopy = numCopy / 10;
		}

		if (sum == N || num == N)
			break;

		num++;
	}

	return num;
}

int main() {
	cin >> N;
	int res = decomp();

	if (res == N)
		cout << 0 << '\n';
	else
		cout << res << '\n';

	return 0;
}