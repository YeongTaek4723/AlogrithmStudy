#include<iostream>
#include<map>

map<char, pair<char, char>> tree;

void preoder(char node){
    if(node == '.')     return;

    cout << node;
    preoder(tree[node].first);
    preoder(tree[node].second);
}

void inorder(char node){
    if(node == '.')     return;

    inorder(tree[node].first);
    cout << node;
    inorder(tree[node].second);
}

void postorder(char node){
    if(node == '.')     return;

    postorder(tree[node].first);
    postorder(tree[node].second);
    cout << node;
}

void main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        char root, left, right;
        cin >> root, left, right;

        tree[root].first = left;
        tree[root].second = right;
    }

    preoder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}