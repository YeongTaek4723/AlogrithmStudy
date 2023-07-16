#include<iostream>

using namespace std;

int arr[500001];
int tmp[500001];
int N, K;
int cnt = 0;

void merge(int arr[], int low, int mid, int high){
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j])        tmp[k++] = arr[i++];
        else                        tmp[k++] = arr[j++];
    }

    while(i <= mid)                 tmp[k++] = arr[i++];
    while(j <= high)                tmp[k++] = arr[j++];

    for(int t = low; t <= high; t++){
        arr[t] = tmp[t];
        cnt++;
        if(cnt == K){
            for(int i = 0; i < N; i++){
                cout << arr[i] << ' ';
            }
        }
    }
}

void merge_sort(int arr[], int low, int high){
    if(low >= high){
        return;
    }

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low , mid, high);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    merge_sort(arr, 0, N - 1);
    if(K > cnt) cout << -1;

    return 0;
}