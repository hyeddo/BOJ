#include <iostream>
using namespace std;

int main() {
	int input, cnt=0;
	cin >> input;
	for (int i = 1; i <= input; i++) {
		if (i < 100) {
			cnt++; //���ڸ���, ���ڸ����� �� ī��Ʈ
		}
		else if (i < 1000) {
			if ((i % 10) - ((i / 10) % 10) == ((i / 10) % 10) - (i / 100)) 
				cnt++;
		}
	}
	cout << cnt;
}