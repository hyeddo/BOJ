#include <iostream>
using namespace std;

#define MAX(x,y) (((x)>(y))?(x):(y))

int numStairs;
int point[301];
int dp[301];

int main() {
	cin >> numStairs;
	
	for (int i = 1; i <= numStairs; i++)
		cin >> point[i];

	dp[0] = 0;
	dp[1] = point[1];
	dp[2] = point[1] + point[2];
	for (int i = 3; i <= numStairs; i++) {
		dp[i] = MAX(dp[i - 3] + point[i - 1] + point[i], dp[i - 2] + point[i]);
	}

	cout << dp[numStairs] << '\n';

	return 0;
}