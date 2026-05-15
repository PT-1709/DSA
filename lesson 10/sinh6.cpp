// sinh ra hoán vị của N phần tử

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int X[1000],n, final = 0;

void ktao(){
    for (int i = 1; i <= n; i++){
        X[i] = i;
    }
}

void sinh(){
    int i = n-1;
    while (i >= 1 && X[i] > X[i+1]){
        --i;
    }
    if (i == 0){
        final = 1;
    }
    else{
        int j = n;
        while (X[i] > X[j]){
            --j;
        }
        swap(X[i], X[j]);
        reverse(X+i+1, X+n+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    ktao();
    while(final == 0){
        for (int i = 1; i <= n; i++){
            cout << X[i] << " ";
        }
        cout << endl;
        sinh();
    }
    
    
    return 0;
}