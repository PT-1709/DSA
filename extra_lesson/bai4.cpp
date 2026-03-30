// học về định lý đồng dư trung hoa, có thể xem formular và formular1 để biết chi tiết


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid_extented(ll n, ll mod){
    n %= mod;
    ll r_prev2 = mod, r_prev1 = n;
    ll x_prev2 = 0, x_prev1 = 1;

    while (r_prev1 != 0){
        ll r_i = r_prev2 % r_prev1;
        ll q_i = r_prev2 / r_prev1;
        ll x_i = x_prev2 - q_i * x_prev1;

        r_prev2 = r_prev1; r_prev1 = r_i;
        x_prev2 = x_prev1; x_prev1 = x_i;
    }
    if (r_prev2 != 1){
        return -1;
    }
    return (x_prev2 % mod + mod)  % mod;
    // nên để return ở ngoài vòng while để tất cả mọi thứ đã đc cập nhật
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, mod1, b, mod2; cin >> a >> mod1 >> b >> mod2; 
    ll mod = mod1 * mod2;
    ll M1 = mod / mod1; 
    ll M2 = mod / mod2; 

    ll y1 = euclid_extented(M1,mod1);
    ll y2 = euclid_extented(M2, mod2);
    
    ll x = (a*M1*y1 + b*M2*y2) % mod;

    cout << x << endl;
    
    return 0;
}