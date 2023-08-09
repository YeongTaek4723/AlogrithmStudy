#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<int, int>> q;

int n;
char map[101][101];
int visit[101][101] = { 0, };

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

void init_visit() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
}

int all_visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

int bfs() {

	int cnt = 0;

	int tx, ty;
	tx = ty = 0;

	while (!all_visit()) { //모두 방문할 때까지		
		q.push(make_pair(tx, ty));
		visit[tx][ty] = 1;
		char c = map[tx][ty];

		while (!q.empty()) { //문자 c에 대한 bfs
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				tx = x + dx[i];
				ty = y + dy[i];

				if (tx < 0 || tx >= n || ty < 0 || ty >= n)
					continue;
				if (visit[tx][ty] == 1)
					continue;
				if (map[tx][ty] != c)
					continue;

				visit[tx][ty] = 1;
				q.push(make_pair(tx, ty));
			}
		}

		for (int i = 0; i < n; i++) { //아직 방문하지 않은 문자 위치
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					tx = i;
					ty = j;
				}
			}
		}

		cnt++;
	}

	return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int a = bfs();  //적록색약이 아닌 사람이 본 개수 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') //G를 R로 변경
				map[i][j] = 'R';
		}
	}

	init_visit();
	int b = bfs();  //적록색약인 사람이 본 개수 

	cout << a << " " << b;


    return 0;
}