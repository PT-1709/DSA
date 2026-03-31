#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll a[], ll n, ll k,ll mid){
    ll cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        if (sum > mid){
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    if (cnt <= k){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k; cin >> n >> k;
    ll a[n];
    ll res = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll left = *max_element(a,a+n);
    ll right = accumulate(a,a+n,0ll);

    while (left <= right){
        ll mid = (left + right) / 2;
        if (check(a,n,k,mid)){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << res << endl;
    
    return 0;
}