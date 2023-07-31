#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin_tie(NULL);
    cout_tie(NULL);

    int N, cnt = 0;
    cin >> N;

    while(N >= 0){
        if(N % 5 == 0){
            cnt += N / 5;
            cout << cnt << endl;
            return 0;
        }

        N -= 3;
        cnt++;
    }

    cout << -1 << endl;
    return 0;
}