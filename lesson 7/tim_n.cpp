// đề: cho số nguyên tố p và số mũ k, tìm n để trong n! có đủ k số p trong đó

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll vp(ll n, ll p){
    ll ans = 0;
    while (n > 0){
        ans = ans + n/p;
        n/=p;
    }
    return ans;
}

ll find_n(ll p, ll k){
    ll left = 1, right = 1;
    while (vp(right, p) < k){
        right *= 2; // gấp đôi để có thể tìm giới hạn đủ lớn để tìm n
    }

    while (left < right){
        ll mid = (left + right) / 2;
        if (vp(mid,p) >= k){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll p, k; cin >> p >> k;
    cout << find_n(p,k) << endl;
    
    return 0;
}