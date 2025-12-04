// cho 1 dãy số và các truy vấn, mỗi truy vẫn cho l và r , biết trc có bao nhiêu truy vấn, tính tổng lớn nhất của các truy vấn đó

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q; cin >> n >> q;
    int a[100005], d[100005], f[100005];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while (q--){
        int l,r; cin >> l >> r;
        d[l] += 1;
        d[r+1] -= 1;
    }
    for (int i = 1; i<= n; i++){
        if (i == 1) f[i] = d[i];
        else f[i] = f[i-1] + d[i];
    }

    long long sum = 0;
    sort(a+1, a+n+1);
    sort(f+1, f+n+1);
    for (int i= 1; i <= n; i++){
        sum += a[i] * f[i];
    }
    cout << sum << endl;
    
    return 0;
}