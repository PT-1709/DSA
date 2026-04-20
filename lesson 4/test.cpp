#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int a[n] = {0};


    int q; cin >> q;
    while (q--){
        int l,r,k; cin >> l >> r >> k;
        a[l] += k;
        a[r+1] -= k;
    }

    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        cout << sum << " ";
    }
    
    return 0;
}