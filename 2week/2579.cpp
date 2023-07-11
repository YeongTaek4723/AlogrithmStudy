#include<iostream>

using namespace std;

int arr[301], dp[301];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }


    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1], arr[2]) + arr[3];

    for(int i = 4; i <= N; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
    }

    cout << dp[N] << endl;

    return 0;
}