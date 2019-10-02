#include <iostream>
using namespace std;

int T, n;
int dp[11] = { 0, 1, 2, 4 };

int add123(void) {
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	
	return dp[n];
}

int main() {
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << add123() << '\n';
	}

	return 0;
}