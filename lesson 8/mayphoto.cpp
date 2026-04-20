// tìm thời gian để có thể in ra đủ số lượng n yêu cầu biết có 2 máy photo, 1 máy x giây và 1 máy y giây
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll n, ll x , ll y, ll mid){
    ll ans = 0;
    ans += mid / x;
    ans += mid / y;
    return ans >=n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n,x,y; cin >> n >> x >> y;
    ll left = 0, right = 10;
    ll res = -1;
    while (left <= right){
        ll mid = (left + right ) / 2;
        if(check(n,x,y,mid)){
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