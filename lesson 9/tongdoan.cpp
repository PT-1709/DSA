// tổng độ dài đc phủ ít nhất 1 đoạn thẳng là bao nhiu, ví dụ nếu là [1,5]
// and [2,7] thì độ dài đoạn nè là 1 -> 7

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<pair<ll,ll>> vp;
    for (int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        vp.push_back({x,+1});
        vp.push_back({y,-1});
    }

    sort(vp.begin(), vp.end());

    ll ans = 0, cnt = 0, prev_x = vp[0].first;
    int i = 0;
    while (i < (ll)vp.size()){
        ll x = vp[i].first;
        if (cnt > 0){
            ans += (x - prev_x);
        }
        while (i < (ll)vp.size()  && vp[i].first == x){
            cnt += vp[i].second;
            i++;
        }
        prev_x = x;
    }
    cout << ans << endl;
    return 0;
}