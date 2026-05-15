// cho N và K lấy tổ hợp chập K của N và cho sẵn 1 tổ hợp, theo thứ tự thì tổ hợp đó đứng vị trí bao nhiêu

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int X[1000], n,k, A[1000], final = 0;

void ktao(){
    for (int i = 1; i <= k; i++){
        X[i] = i;
    }
}

void sinh(){
    int i = k; 
    while (i >= 1 && X[i] == n - k + i){
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
    for (int i = 1; i <= k; i++){
        cin >> A[i];
    }

    ktao();
    int cnt = 0;
    while (final == 0){
        cnt++;
        bool check = true;
        for (int i = 1; i <= k; i++){
            if (A[i] != X[i]){
                check = false;
                break;
            }
        }
        if (check == true){
            cout << cnt << endl;
            return 0;
        }
        sinh();
    }

    cout << cnt << endl;
    
    return 0;
}