// bài này test code của đồng dư thương
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9 + 7;

ll euclid_extended (ll a){
    a%= mod;
    ll r_prev2 = mod, r_prev1 = a;
    ll x_prev2 = 0, x_prev1 = 1;

    if (a == 1) return 1;
    while (r_prev1 != 0){
        ll q_i = r_prev2 / r_prev1;
        ll r_i = r_prev2 % r_prev1;
        ll x_i = x_prev2 - q_i * x_prev1;

        if (r_i == 1){
            if (x_i < 0){
                return x_i + mod;
            }
            return x_i;
        }

        r_prev2 = r_prev1; r_prev1 = r_i;
        x_prev2 = x_prev1; x_prev1 = x_i;
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a,b; cin >> a >> b;
    ll x = euclid_extended(b);
    ll ans = 1;
    for (ll i = 1; i <= a; i++){
        ans = (ans * i ) % mod;
    }
    

    cout << (ans % mod) * ( x % mod) % mod << endl; 

    
    return 0;
}