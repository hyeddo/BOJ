#include <iostream>
using namespace std;

int main() {
	int input, count=0;
	cin >> input;
	if (input > 0 && input <= 1000) {
		for (int i = 1; i <= input; i++) {
			if (i < 100) {
				count++; //���ڸ���, ���ڸ����� �� ī��Ʈ
			}
			else if (i < 1000) {
				if ((i % 10) - ((i / 10) % 10) == ((i / 10) % 10) - (i / 100)) count++;
			}
		}
	}
	else cout << "���� ���� ���� �Է��ϼ���" << endl;

	cout << count;
}