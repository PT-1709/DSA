// nghịch đảo a của module m
// khi dùng phép thương trong đồng dư thì có thể nhân với nghịch đảo của số đó với mod mà đề bài cho
// idea nhìn vào ảnh
// đối vs bài này, y ko quá quan trọng còn x là phần nghịch đảo cần tìm


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid_extendted(ll n, ll mod){
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

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, m; cin >> a >> m;
    cout << euclid_extendted(a,m) << endl;
    
    return 0;
}