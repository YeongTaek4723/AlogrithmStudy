#include <iostream>
#define MAX 1025

using namespace std;

int arr[MAX][MAX], dp[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    // 백준에서 시간초과가 생기는 경우를 줄여준다 - 간단하게 말해서 3개의 코드를 작성하면 입출력 속도가 빨라져 시간초과로 틀리는 문제가 맞게 된다. 

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];  
            // dp배열에 (i, j)의 값은 (i -1, j)의 합과 (i, j -1)의 합을 더한 뒤 중복되어 합해진 (i - 1, j -1)의 값을 빼주면 된다.
        }
    }

    int x1, y1, x2, y2;

    for(int i = 0; i < M; i++){
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]; 
        // 구간 합의 경우 예를 들어 입력값 2 2 3 4 , (2, 2) ~ (3, 4)까지의 합을 구하는 경우 
        // (3, 4)의 구간 합에서 (1, 4)의 구간 합과 (3, 1)의 구간 합을 뺀뒤 중복되어 뺀 (1, 1)구간 합을 더하면 된다.
        cout << sum << '\n';
    }
}