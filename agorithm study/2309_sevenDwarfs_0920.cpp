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

	for (int j = 0; j < 9; j++) {
		for (int k = j + 1; k < 9; k++) {
			if ((dwarf[j] + dwarf[k]) == falseSum)
			{
				dwarf[j] = -1;
				dwarf[k] = -1;

				sort(dwarf, dwarf + 9);

				for (int m = 2; m < 9; m++)
					cout << dwarf[m] << '\n';

				return 0;
			}
		}
	}
}