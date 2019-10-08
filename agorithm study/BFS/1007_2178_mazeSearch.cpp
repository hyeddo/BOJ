#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct {
	int row;
	int col;
}Pos;

int N, M;
int maze[102][102];
int dist[102][102];
bool isVisit[102][102];
queue<Pos> qu;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void BFS() {
	Pos start = { 1,1 };
	qu.push(start);
	dist[start.row][start.col] = 1;
	isVisit[start.row][start.col] = true;

	while (!qu.empty()) {
		Pos curr = qu.front();
		
		if (curr.row == N && curr.col == M)
			break;
	
		qu.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = { curr.row + dy[i], curr.col + dx[i] };
			if (isVisit[next.row][next.col] == true)
				continue;
			if (maze[next.row][next.col] == 1) {
				dist[next.row][next.col] = dist[curr.row][curr.col] + 1;
				qu.push(next);
				isVisit[next.row][next.col] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	string* input;
	input = new string[N];

	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			maze[i][j] = -1;
			
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> input[i];
		for (int j = 0; j < M; j++)
			maze[i + 1][j + 1] = (int)input[i][j] - '0';
	}

	BFS();
	cout << dist[N][M] << '\n';
}