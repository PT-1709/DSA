// cách làm : b1: sàng tìm SPF -> b2: tính lũy thừa i^k mod m -> b3: cộng dồn và lấy mod

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 1e6 + 5;
const int mod = 1e9 + 7;
ll spf[MAX];
ll F[MAX];

void sieve_spf(){
    for (ll i = 1; i < MAX; i++){
        spf[i] = i;
    }

    for (ll i = 2;i < MAX; i++ ){
        if (spf[i] == i){
            for (ll j = i * i; j < MAX; j+= i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

ll power(ll a, ll b){
    ll res = 1; a %= mod;
    while (b > 0){
        if (b % 2 == 1){
            res = (res * a) % mod;
        }
        a = (a*a) % mod;
        b /= 2;
    }
    return res;
}

ll caculater(ll _n, ll _k){
    F[1] = 1;
    ll total_S = 1;

    for (int i = 2; i <= _n; i++){
        if (spf[i] == i){
            F[i] = power(i,_k);
        }
        else{
            F[i] = (F[spf[i]] * F[i/spf[i]]) % mod;
        }
        total_S = (total_S + F[i]) % mod;
    }
    return total_S;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve_spf();
    int n, k;
    cin >> n >> k; 
    
    cout << caculater(n,k) << endl;
    
    
    return 0;
}