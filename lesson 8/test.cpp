#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int a[],int n, int l, int mid){
    int res = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= mid){
            res += (a[i] - mid);
        }
    }

    return res >= l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, l; cin >> n >> l;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = -1;
    int left = 0, right =   *max_element(a,a+n);

    while (left <= right){
        int mid = (left + right) /2;
        if (check(a,n,l,mid)){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans;
    
    return 0;
}
//test xem nhuw thge naof nhe