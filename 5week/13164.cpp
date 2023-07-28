#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> arr;
vector<int> cost;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    arr.resize(N);
    cost.resize(N-1);

    for(int i = 0; i < N; i++)      cin >> arr[i];

    sort(arr.begin(), arr.end());

    for(int i = 1; i < N; i++) cost[i - 1] = arr[i] - arr[i - 1];

    sort(cost.begin(), cost.end());

    int result = 0;

    for(int i = 0; i < N - K; i++)  result += cost[i];

    cout << result << endl;

    return 0;
}