// cho các đoạn, có nhiều nhất bao nhiêu đoạn chồng lên nhau ?

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector <pair<int,int>> vp;
    while (n--){
        int x,y; cin >> x >> y;
        vp.push_back({x,+1});
        vp.push_back({y,-1});
    }

    
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.first != b.first)
        {
            return a.first < b.first;
        }

        return a.second > b.second;
    });

    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < (int)vp.size(); i++){
        cnt += vp[i].second;
        ans = max(ans,cnt);
    }

    cout << ans << endl;


    return 0;
}