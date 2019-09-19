#include <iostream>
using namespace std;

int main() {
	int input, count=0;
	cin >> input;
	if (input > 0 && input <= 1000) {
		for (int i = 1; i <= input; i++) {
			if (i < 100) {
				count++; //한자리수, 두자리수는 다 카운트
			}
			else if (i < 1000) {
				if ((i % 10) - ((i / 10) % 10) == ((i / 10) % 10) - (i / 100)) count++;
			}
		}
	}
	else cout << "범위 안의 수를 입력하세요" << endl;

	cout << count;
}