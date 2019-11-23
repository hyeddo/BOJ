#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;

typedef struct {
	int row, col;
}Dir;

Dir moveDir[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int N, M;
int r, c, d;
int robot[MAX][MAX];
int result = 0;
queue<pair<pair<int, int>, int>> q;

void clear() {
	q.push({ { r,c }, d });

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int dir = q.front().second;
		if (robot[y][x] == 0) {
			robot[y][x] = 2;
			result++;
		}
		q.pop();

		bool flag = false;

		for (int i = 0; i < 4; i++) {
			int nextDir = (dir + (3 - i)) % 4;
			int nextY = y + moveDir[nextDir].row;
			int nextX = x + moveDir[nextDir].col;

			if(0<=nextY&&nextY<N&&0<=nextX&&nextX<M)
				if (!robot[nextY][nextX]) {
					q.push({ {nextY, nextX},nextDir });
					flag = true;
					break;
				}
		}

		if (!flag) {
			int beforeY = y - moveDir[dir].row;
			int beforeX = x - moveDir[dir].col;
			if ((0 <= beforeY && beforeY < N && 0 <= beforeX && beforeX < M) && robot[beforeX][beforeY] != 1)
				q.push({ {beforeY, beforeX}, dir });
			else
				break;
		}
	}
}

int main() {
	cin >> N >> M;
	
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> robot[i][j];

	clear();

	cout << result << '\n';
	return 0;	
}
