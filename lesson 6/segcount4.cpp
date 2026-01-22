// đếm số dãy con sao cho tk lớn nhất và tk bé nhất ko vượt quá k đơn vị

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> ms;
    int left = 0, right = 0, ans = 0;
    for (; right < n; right++){
        ms.insert(a[right]);
        while (ms.size() > 1 && *ms.rbegin() - *ms.begin() > k){
            auto it = ms.find(a[left]);
            ms.erase(it);
            left++;
        }
        ans += right - left + 1;
    }

    cout << ans << endl;
    
    return 0;
}