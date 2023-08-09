#include<iostream>

using namespace std;

int map[101][101] = { 0 };
int visit[101] = { 0 };
int cnum, ans = 0;

void dfs(int n) {
    ans++;
    visit[n] = 1;
    for (int i = 1; i <= cnum; i++) {
        if (map[n][i] && !visit[i])
            dfs(i);
    }
    
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int n;
    int x, y;
    cin >> cnum >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }

    dfs(1);
    cout << ans - 1 << endl;

	return 0;
}
