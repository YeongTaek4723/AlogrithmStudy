#include<iostream>

using namespace std;

int arr[1000], dp[1000];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);

    int N;
    cin >> N;


    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1)    dp[i] = dp[j] + 1;
        }
    }

    int max = 0;
    for(int i = 0; i < N; i++){
        if(max < dp[i])     max = dp[i];
    }

    cout << max << endl;

    return 0;
}