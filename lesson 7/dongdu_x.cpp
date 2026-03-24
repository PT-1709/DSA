#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll tichdu = 1;
    int n; cin >> n;
    for (int i = 0; i < n ; i++){
        ll t; cin >> t;
        tichdu *= (t % mod);
        tichdu %= mod;
    }

    cout << tichdu % mod << endl;
    
    return 0;
}