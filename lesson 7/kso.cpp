// tìm k chữ số cuối cùng của n ^ m
// đối với phép trừ, có trường hợp số dư có thể thành âm thì ta + vs k để về số dương

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,m,k; cin >> n >> m >> k;
    int mod = pow(10,k);

    ll result = 1 % mod;
    for (int i = 0; i < m; i++){
        result *= ((n%mod)) % mod;
        result %= mod; 
    }
    cout << result%mod << endl;
    
    return 0;
}