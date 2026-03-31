// tính số cách chọn của tổ hợp chập k của n

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9+ 7;

ll fermat_small(ll n){
    n %= mod;
    ll m = mod -2;
    ll res = 1;
    while (m > 0){
        if (m % 2 == 1){
            res = (res * n) % mod;
        }
        n = (n * n) % mod;
        m /= 2;
    }
    return res;
}

ll giaithua(ll n){
    ll res = 1;
    for (int i = 2; i <= n; i++){
        res = (res *i) % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    ll fact_n = giaithua(n);
    ll fact_k = giaithua(k);
    ll fact_n_k = giaithua(n-k);

    ll nghich_fact_k = fermat_small(fact_k);
    ll nghich_fact_n_k = fermat_small(fact_n_k);

    ll result = (fact_n % mod) * (nghich_fact_k % mod) % mod;
    result = result * (nghich_fact_n_k % mod) % mod;

    cout << result << endl;

    
    return 0;
}