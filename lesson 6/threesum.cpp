// ba so co + lai co = k ko

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 2; i++){
        int l = i + 1, r = n - 1;
        while (l < r){
            if (a[r] + a[l] == k - a[i]){
                cout << "Yes\n";
                return 0;
            }
            else if (a[r] + a[l] < k - a[i]) l++;
            else r--;
        }
    }
    cout << "No\n";
    return 0;
}