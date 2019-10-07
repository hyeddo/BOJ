#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int N, minPrice;
int RGB[MAX][3];
int cache[MAX][3];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
	}

	cache[0][0] = RGB[0][0];
	cache[0][1] = RGB[0][1];
	cache[0][2] = RGB[0][2];

	for (int i = 1; i < N; i++) {
		cache[i][0] = min(cache[i - 1][1], cache[i - 1][2]) + RGB[i][0];
		cache[i][1] = min(cache[i - 1][0], cache[i - 1][2]) + RGB[i][1];
		cache[i][2] = min(cache[i - 1][0], cache[i - 1][1]) + RGB[i][2];
	}

	minPrice = min(min(cache[N - 1][0], cache[N - 1][1]), cache[N - 1][2]);

	cout << minPrice << '\n';
}