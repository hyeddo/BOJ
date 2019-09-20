#include <iostream>
using namespace std;

int main() {
	int H, M, H2, M2;
	cin >> H >> M;
	if (M < 45) {
		M2 = M + 15;
		if (H < 1) H2 = 23;
		else H2 = H - 1;
	}
	else {
		M2 = M - 45;
		H2 = H;
	}

	cout << H2 << " " << M2;
}