#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,s; cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int left = 0, right = 0, tong = 0, res = 0;
    for (;right < n; right++){
        tong += a[right];
        while (tong > s){
            tong -= a[left];
            left++;
        }
        res += right - left + 1;
    }

    cout << res << endl;
    
    return 0;
}