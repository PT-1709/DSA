#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll m){
    ll t = sqrt(m);
    for (int i = 2; i <= t; i++){
        if (m % i == 0){
            return false;
        }
    }
    return true;
}

ll fermat_small(ll a, ll exp, ll m){
    if (a % m == 0){
        cout << "Không thể lấy số nghịch đảo";
        return 0;
    }

    ll res = 1;
    a %= m;
    while (exp > 0){
        if (exp % 2 == 1){
            res = (res * a)  % m;
        }
        a = (a * a) % m;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a,m; cin >> a >> m;
    if (!check(m)){
        cout << "Không thể lấy số nghịch đảo";
        return 0;
    }

    ll ans = fermat_small(a,m-2,m);
    cout << ans << endl;
    
    return 0;
}