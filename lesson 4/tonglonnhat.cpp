#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,t; cin >> n >> t;
    vector <int> a(n), d(n,0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    while (t--){
        int l,r; cin >> l >> r;
        d[l-1] += 1;
        if (r <= n){
            d[r] -= 1;
        }
    }
    
    for (int i = 1; i < n; i++) {
        d[i] += d[i - 1];
    }
    //d.pop_back();

    cout << endl;
    for (int x : a){
        cout << x << " ";
    }
    cout << endl;
    for (int x : d){
        cout << x << " ";
    }
    cout << endl;

    
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());

    cout << endl;
    for (int x : a){
        cout << x << " ";
    }
    cout << endl;
    for (int x : d){
        cout << x << " ";
    }
    cout << endl;

    long long sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i] * d[i];
    }
    cout << endl;
    cout << sum << endl;
    
    return 0;
}