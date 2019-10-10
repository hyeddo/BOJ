#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, target1, target2, m;
vector<int> relation[101];//관계행렬
bool isVisit[101];
int numCnt[101];//촌수계산
queue<int> qu;
bool isValid = true;//관계 있는지 없는지

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
			if (isVisit[next])//이미 방문했으면 다음걸로
				continue;
			qu.push(next);
			isVisit[next] = true;
			numCnt[next] = numCnt[curr] + 1;//촌수 +1
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
		relation[from].push_back(to);//양방향
		relation[to].push_back(from);
	}
	memset(isVisit, false, sizeof(isVisit));//false로 채워두기
	memset(numCnt, 0, sizeof(numCnt));//0으로 채워두기

	BFS();

	if (isValid)
		cout << numCnt[target2] << '\n';
	else cout << -1 << '\n';
}