#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];

void BinarySearch(int arr[], int key, int N){
    int low = 0;
    int high = N - 1;
    int mid;

    while(low <= high){
        mid = (low + high) / 2;

        if(arr[mid] < key)      low = mid + 1;
        else if(arr[mid] > key) high = mid - 1;
        else{
            cout << '1' << '\n';
            return;
        }
    }

    cout << '0' << '\n';
    return;
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
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        BinarySearch(arr, num, N);
    }

    return 0;
}