#include <iostream>
using namespace std;

int N, S, cnt=0, arr[20];

void subsequence(int index, int sum) {
	sum += arr[index];

	if (index >= N)
		return;
	if (sum == S)
		cnt++;

	subsequence(index + 1, sum - arr[index]);
	subsequence(index + 1, sum);
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	subsequence(0, 0);

	cout << cnt;

	return 0;
}