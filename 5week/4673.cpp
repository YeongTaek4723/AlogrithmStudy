#include<iostream>

using namespace std;

int d(int number){
    int num = number;

    while(number != 0){
        num = num + (number % 10);
        number /= 10;
    }

    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin_tie(NULL);
    cout_tie(NULL);

    bool check[10001] = {false};
    for(int i = 1; i < 10001; i++){
        int n = d(i);

        if(n < 10001)   check[n] = true;
    }

    for(int i = 1; i < 10001; i++){
        if(!check[i])       cout << i << "\n";
    }

    return 0;
}