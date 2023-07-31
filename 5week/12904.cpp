#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin_tie(NULL);
    cout_tie(NULL);

    string S, T;
    cin >> S >> T;

    while(N >= 01){
        if(T[T.length() - 1] == 'A')    T.pop_back();

        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }

        if(S.length() == T.length()){
            if(S == T)      cout << 1 << endl;
            else            cout << 0 << endl;
            break;
        }
    }

    return 0;
}