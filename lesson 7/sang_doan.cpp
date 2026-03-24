// sàng số nguyên tố trên đoạn, giới hạn của sàng bth chỉ đến 10^7
// điều kiện R - L + 1 <= 10^7

// L = 10^9 and R = 10^9 + 500000
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sang (ll l, ll r){
    int p[r - l + 1];
    for (int i = 0; i < r - l + 1; i++){
        p[i] = 1;
    }
    for (ll i = 2; i <= sqrt(r); i++){
        for (ll j = max(i*i, ((l + i - 1) / i) * i) ; j <= r; j+= i){
            // công thức trên tìm bội nhỏ nhất lớn hơn = l để ko bị vượt quá giới hạn
            p[j - l] = 0;
        }
    }
    for (ll i = max(2ll,l); i <= r; i++){
        if (p[i - l]){
            cout << i << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sang(10,47);
    
    return 0;
}