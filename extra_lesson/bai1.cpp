// tìm số dư của 2^100 mod 13
// thực ra cái mũ m-1 chỉ là 1 cái số khi chia dư vẫn có kết quả như ban đầu thôi
// công thức là dư của a^b mod m  = số dư của a ^ (b mod m-1) mod m

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll n, ll mod){
    ll t = sqrt(mod);
    for (int i = 2; i <= t; i++){
        if (mod % i == 0){
            return false;
        }
    }   
    if (mod % n == 0){
        return false;
    }
    return true;
}

ll fermat_small(ll a, ll m, ll mod){
    ll res = 1;
    while (m > 0){
        if (m % 2 == 1){
            res =  (res * a ) % mod;
        }
        a = (a*a) % mod;
        m /= 2;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,m,mod; cin >> n >> m >> mod;  
    
    ll chu_ky = mod - 1;
    ll m_habac = m % chu_ky;
    cout << fermat_small(n,m_habac,mod) << endl;  
     
    return 0;
}