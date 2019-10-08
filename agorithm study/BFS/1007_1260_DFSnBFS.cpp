#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, V;
int visitCnt = 0;
bool visited[1001];
vector<int> edge[1001];
queue<int> qu;

void DFS(int currVertex) {
	if (visitCnt == N)
		return;
	if (visited[currVertex])
		return;
	visited[currVertex] = true;
	visitCnt++;

	cout << currVertex << " ";

	for (int i = 0; i < edge[currVertex].size(); i++) {
		int nextVertex = edge[currVertex][i];
		DFS(nextVertex);
	}
}

void BFS() {
	qu.push(V);

	while (!qu.empty()) {
		int front = qu.front();
		qu.pop();

		if (visitCnt == N)
			break;
		if (visited[front])
			continue;

		visited[front] = true;
		visitCnt++;
		cout << front << " ";

		for (int i = 0; i < edge[front].size(); i++) {
			int nextV = edge[front][i];
			qu.push(nextV);
		}
	}
}

int main() {
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	
	DFS(V);
	cout << '\n';
	visitCnt = 0;
	memset(visited, false, sizeof(visited));
	BFS();
}