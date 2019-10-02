#include <iostream>
using namespace std;

int k, S[13], lotto[6];

void printLotto(int N, int len) {
	if (len == 6) {
		for (int i = 0; i < 6; i++)
			cout << lotto[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = N; i < k; i++) {
		lotto[len] = S[i];
		printLotto(i + 1, len + 1);
	}
}

int main() {
	while (1) {
		cin >> k;

		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
			cin >> S[i];
		printLotto(0, 0);
		cout << '\n';
	}
	return 0;
}