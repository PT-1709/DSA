// https://docs.google.com/document/d/11Jx3R8E-6wzwRNGbNvULWtqEVU5-vWxc24ztkJZd63k/edit?usp=sharing

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll a[], int n, int c, int mid){
    int count = 1;
    int last_pos = a[0];

    for (int i = 1; i < n; i++){
        if (a[i] - last_pos >= mid){
            count++;
            last_pos = a[i];
        }
    }
    return count >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,c; cin >> n >> c;
    ll a[n];
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a,a+n);
    int left = 0, right = a[n-1] - a[0];
    int ans = 0;

    while (left <= right){
        int mid = (left + right) / 2;
        if (check(a,n,c,mid)){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << ans << endl;
    
    return 0;
}