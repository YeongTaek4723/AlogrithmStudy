#include<iostream>
#include<algorithm>

using namespace std;

int arr[500001];

void BinarySearch(int arr[], int key, int N){
    int low = 0, high = N - 1, mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(arr[mid] == key){
            cout << '1' << ' ';
            return;
        }
        else if(arr[mid] < key)     low = mid + 1;
        else                        high = mid - 1;
    }

    cout << '0' << ' ';
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
    cin >> M;
    int num;
    for(int i = 0; i < M; i++){
        cin >> num;
        BinarySearch(arr, num, N);
    }

    cout << '\n';

    return 0;
}