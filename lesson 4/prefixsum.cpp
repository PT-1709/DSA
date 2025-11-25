#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, tc; cin >> n >> tc;

    int a[n+1], prefix[n+1]  ;
    for (int i = 0; i < n; i++){
        if (i == 0){
            cin >> a[i];
            prefix[i] = a[i];
        }
        else{
            cin >> a[i];
            prefix[i] = prefix[i-1] + a[i];
        }
    }
    vector <int> v;
    while (tc--){
        int l,r; cin >> l >> r;
        if (l == 0){
            v.push_back(prefix[r]);
            continue;
        }
        int kq = prefix[r] - prefix[l-1];
        v.push_back(kq);
    }

    for (int x : v){
        cout << x << endl;
    }
    
    return 0;
}