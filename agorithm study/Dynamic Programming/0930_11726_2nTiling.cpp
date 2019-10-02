#include <iostream>
using namespace std;

int dp[1000] = {1,2};

int main() {
	int n;

	cin >> n;

	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}

	cout << dp[n-1];

	return 0;
}