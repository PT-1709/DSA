// chặt gỗ xây nhà
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int a[], ll n, ll l, ll mid ){
    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > mid){
            ans += (a[i] - mid);
        }
    }

    if (ans >= l){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, l; cin >> n >> l;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int h = -1;
    ll left = 0, right = 1e9;
    while (left < right){
        ll mid = (left + right ) / 2;
        if(check(a,n,l,mid)){
            h = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << h << endl;
    
    return 0;
}