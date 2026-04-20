// sinh xâu nhị phân mũ N tức là nó sẽ từ 0 đến 2^N - 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int X[1000];
int n;

void ktao(){
    for (int i = 1; i <= n; i++){
        X[i] = 0;
    }
}

bool check(){
    for (int i = 1; i <= n; i++){
        if (X[i] == 0) return false;
    }
    return true;
}

void sinh(){
    int i = n;
    while (i >= 0 && X[i] == 1){
        X[i] = 0;
        --i;
    }
    if (i != 0){
        X[i] = 1;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    ktao();
    while(check() == false){
        for (int i = 1; i <= n; i++){
            cout << X[i] << " ";
        }
        cout << endl;
        sinh();
    }
    for (int i = 1; i <= n; i++){
        cout << X[i] << " ";
    }
    
    
    return 0;
}