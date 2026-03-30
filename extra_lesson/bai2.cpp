// đối với cơ số thì chia lấy dư trực tiếp cho mod còn số mũ thì chia lấy dư với mod - 1


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pow(ll a, ll m, ll mod){
    ll res = 1;
    a %= mod;
    while (m > 0){
        if (m % 2 == 1){
            res = (res * a) % mod;
        }
        a = (a*a) % mod;
        m /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll coso1, mu1, coso2, mu2, mod;
    cin >> coso1 >> mu1 >> coso2 >> mu2 >> mod;

    ll coso1sau = coso1 % mod;
    ll coso2sau = coso2 % mod;

    ll mod1= mod - 1;

    ll mu1sau = mu1 % mod1;
    ll mu2sau = mu2 % mod1;

    ll res1 = pow(coso1sau,mu1sau,mod);
    ll res2 = pow(coso2sau,mu2sau,mod);

    ll total = (res1 + res2) % mod;
    if (total == 0){
        cout << "Dieu phai chung minh!" << endl;
    }

    return 0;
}