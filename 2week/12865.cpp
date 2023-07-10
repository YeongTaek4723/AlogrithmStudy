#include<iostream>

using namespace std;

int w[101], v[101], dp[101][100001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            // 물건이 들어가는 경우
            if(j >= w[i])   dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            // max로 i-1의 값(이전 값)과 i-1에서 j에 w[i]의 값을 뺸곳의 값과 비교해 더 큰 값을 대입 

            // 물건이 들어가지 않는 경우
            else    dp[i][j] = dp[i - 1][j];
            // 물건을 넣을 수 없으므로 이전 값을 그대로 가져온다.
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}