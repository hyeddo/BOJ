#include <iostream>
using namespace std;

int main() {
	int N, min = 0, max = 0;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	min = arr[0];

	for (int i = 0; i < N; i++) {
		if (min > arr[i])
			min = arr[i];
	}

	max = arr[0];

	for (int i = 0; i < N; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	cout << min << " " << max;
}