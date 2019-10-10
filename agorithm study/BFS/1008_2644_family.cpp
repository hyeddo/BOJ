#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, target1, target2, m;
vector<int> relation[101];//�������
bool isVisit[101];
int numCnt[101];//�̼����
queue<int> qu;
bool isValid = true;//���� �ִ��� ������

void BFS() {
	qu.push(target1);
	isVisit[target1] = true;
	numCnt[target1] = 0;

	while (!qu.empty()) {
		int curr = qu.front();
	
		if (curr == target2)
			break;

		qu.pop();

		for (int i = 0; i < relation[curr].size(); i++) {
			int next = relation[curr][i];
			if (isVisit[next])//�̹� �湮������ �����ɷ�
				continue;
			qu.push(next);
			isVisit[next] = true;
			numCnt[next] = numCnt[curr] + 1;//�̼� +1
		}
	}
	if (qu.empty())
		isValid = false;
}

int main() {
	cin >> n >> target1 >> target2 >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		relation[from].push_back(to);//�����
		relation[to].push_back(from);
	}
	memset(isVisit, false, sizeof(isVisit));//false�� ä���α�
	memset(numCnt, 0, sizeof(numCnt));//0���� ä���α�

	BFS();

	if (isValid)
		cout << numCnt[target2] << '\n';
	else cout << -1 << '\n';
}