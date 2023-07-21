#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priotity_queue<int, vector<int>, greater<int>> qu;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;


    for(int i = 0; i<N; i++){
        int num;
        cin >> num;

        if(num == 0){
            if(qu.empty())      cout << '0' << '\n';
            else{
                cout << qu.top() << '\n';
                qu.pop();
            }
        }

        else    qu.push(num);
    }


    return 0;
}