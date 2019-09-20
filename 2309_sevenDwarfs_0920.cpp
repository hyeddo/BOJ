#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dwarf[9], sum=0, falseSum=0;
	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	falseSum = sum - 100;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; k++) {
			if ((dwarf[i] + dwarf[j]) == falseSum)
			{
				dwarf[i] = -1;
				dwarf[j] = -1;

				sort(dwarf, dwarf + 9);

				for (int m = 2; m < 9; m++)
					cout << dwarf[m] << '\n';

				return 0;
			}
		}
	}
}
