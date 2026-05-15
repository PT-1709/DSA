// sinh tổ hợp chập K của N phần tử
//tổ hợp đầu tiên n,n+1,n+2,n+k
// tổ hợp cuối: n-k+1,n-k+2,...,n

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int X[1000], n,k, final = 0;

void ktao(){
    for (int i = 1; i <= k; i++){
        X[i] = i;
    }
}

void sinh(){
    int i = k;
    while (i >= 0 && X[i] == n - k + i){
        --i;
    }
    if (i == 0){
        final = 1;
    }
    else{
        X[i]++;
        for (int j = i + 1; j <= k; j++){
            X[j] = X[j-1] + 1;
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    ktao();
    while (final == 0){
        for (int i = 1; i <= k; i++){
            cout << X[i] << " ";
        }
        cout << '\n';
        sinh();
    }
    
    
    return 0;
}