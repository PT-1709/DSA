// tính a ^ b theo lũy thừa nhị phân
// a^b % c
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binpow(ll a, ll b, ll c){
    if (b == 0){
        return 1;
    }
    ll x = binpow(a, b/2, c);
    if (b % 2 == 1){
        return (x % c) * (x % c) % c * (a % c) % c;
    }
    else{
        return (x % c) * (x % c) % c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << binpow(2,100,10) << endl;;
    
    return 0;
}