// tìm nghịch đảo của 7 mod 11 dư 5
// thay vì dư 1 thì giờ là dư 5


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fermat_small(ll a, ll mod, ll m, ll r){  // a = số , mod là chia và r là dư
    a %= mod;
    ll res = 1;
    while (mod > 0){
        if (mod % 2 == 1){
            res = (res * a) % m;
        }
        a = (a*a) % m;
        mod /= 2;
    }
    ll x = res * r % m;
    return x;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a,m,r; cin >> a >> m >> r;
    ll mod = m-2;
    ll x = fermat_small(a,mod,m,r);

    cout << x << endl;
    
    return 0;
}