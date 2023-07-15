#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    
    int N, x;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
    cin >> x;

    int low = 0, high = N - 1, cnt = 0;
    while(low < high){
        if(arr[low] + arr[high] == x){
            low++;
            high--;
            cnt++;
        }
        else if(arr[low] + arr[high] < x){
            low++;
        }
        else if(arr[low] + arr[high] > x){
            high--;
        }
    }

    cout << cnt << '\n';

    return 0;
}