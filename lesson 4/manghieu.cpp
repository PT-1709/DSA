// mảng hiệu: differece array
// mảng hiêu: a[i] - a[i - 1]
// nếu cộng dồn mảng hiệu thì sẽ quay về mảng ban đầu
// chỉ cần thay đổi D[L] và D[R +1] thì sau đó về mảng cộng dồn nó sẽ tự động thay đổi
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> d(n, 0);

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        d[l] += k;
        if (r + 1 < n) {
            d[r + 1] -= k;
        }
    }

    // Khôi phục mảng cuối cùng
    vector<long long> f(n);
    f[0] = d[0];
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] + d[i];
    }

    for (auto x : f) {
        cout << x << " ";
    }

    
    
    /*int n, tc; cin >> n >> tc;  code mảng hiệu này rất ngây thơ
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    while (tc--){
        int l, r, k; cin >> l >> r >>k;
        for (int i = l; i <= r; i++){
            a[i] = a[i] + k;
        }

        for (int x : a){
            cout << x << " ";
        }
    }*/
    return 0;
}