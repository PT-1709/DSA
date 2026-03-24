#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int du = 0;
    for (int i = 0; i < n; i++){
        int t; cin >> t;
        du += (t % mod);
        du %= mod;
    }

    cout << du % mod << endl; 
    
    return 0;
}