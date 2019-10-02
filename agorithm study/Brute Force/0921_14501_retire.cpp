#include <iostream>
using namespace std;

#define Max(x, y) (((x)>(y))?(x):(y))

int N, ans, T[16], P[16];

void maxProfit(int day, int profit) {
	if (day >= N + 1) {
		ans = Max(profit, ans);
		return;
	}
	if (day + T[day] <= N + 1)
		maxProfit(day + T[day], profit + P[day]);
	if (day + 1 <= N + 1) 
		maxProfit(day + 1, profit);
}

int main() {
	cin >> N;
	
	for (int i = 1; i < N+1; i++)
		cin >> T[i] >> P[i];
	
	maxProfit(1, 0);

	cout << ans;
}