// Cho N đoạn thẳng trên trục số, đoạn thứ i có dạng [Li, Ri]
//(Li ≤ Ri, các đầu mút là số nguyên).
//Hai đoạn được gọi là giao nhau nếu chúng có ít nhất một điểm chung.
//Hãy đếm số cặp đoạn (i, j), i < j sao cho đoạn i và đoạn j giao nhau.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n; cin >> n;
    vector<pair<ll,ll>> vp;
    for (int i = 0; i < n; i++){
        int l,r; cin >> l >> r;
        vp.push_back({l,+1});
        vp.push_back({r,-1});
    }

    sort(vp.begin(), vp.end(), [](pair<ll,ll> a, pair<ll,ll> b) {
        if (a.first != b.first){
            return a.first < b.first;
        }
        else{
            return a.second > b.second;
        }
    });

    ll act = 0, res = 0;
    for (auto x : vp){
        if (x.second == +1){
            res += act;
            act++;
        }
        else{
            act--;
        }
    }

    cout << res << endl;
    
    return 0;
}