#include<iostream>
#include <queue>
using namespace std;

int Map[1000][1000];
queue<pair<int, int>> q;
int result = 0;
int M, N;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void BFS() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (Map[nx][ny] == 0) {
					Map[nx][ny] = Map[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];

			if (Map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	BFS();


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}

			if (result < Map[i][j]) {
				result = Map[i][j];
			}
		}
	}

	cout << result - 1 << "\n";

    return 0;
}