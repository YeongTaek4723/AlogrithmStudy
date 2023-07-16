#include<iostream>

using namespace std;

int arr[10001];
int N, K, cnt, result1, result2;

int partition(int arr[], int low, int high){
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] <= arr[high]){
            swap(arr[++i], arr[j]);
            if(++cnt == K){
                result1 = arr[i];
                result2 = arr[j];
            }
        }
    }
    if( i + 1 != high){
        swap(arr[i + 1], arr[high]);
        if(++cnt == K){
            result1 = arr[i + 1];
            result2 = arr[high];
        }
    }
    return i + 1;
}

void QuickSort(int arr[], int low, int high){
    if(low >= high){
        return;
    }

    int mid = partition(arr, low, mid);
    QuickSort(arr, low, mid - 1);
    QuickSort(arr, mid + 1, high);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                      
    cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    QuickSort(arr, 0, N - 1);

    if(cnt < K)     cout << -1;
    else            cout << result1 << ' ' << result2;

    return 0;
}