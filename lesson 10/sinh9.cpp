// sinh phân hoạch

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int X[10000], cnt = 0, n, final = 0;

void ktao(){
    cnt = 1;
    X[1] = n;
}

void sinh(){
    int i = cnt;
    while (i >= 1 && X[i] == 1){
        --i;
    }
    if (i == 0){
        final = 1;
    }
    else{
        X[i]--;
        int d = cnt - i + 1;
        cnt = i;
        int q = d / X[i], r = d % X[i];
        for (int j = 1; j <= q; j++){
            cnt++;
            X[cnt] = X[i];
        }
        if (r){
            cnt++;
            X[cnt] = r;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    ktao();

    while (!final){
        for (int i = 1; i <= cnt; i++){
            cout << X[i] << " ";
        }
        cout << endl;
        sinh();
    }
    
    return 0;
}