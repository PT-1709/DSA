// cho 2 mảng A và B đã đc sắp xếp, đếm xem có bao nhiêu cặp i j mà A[i] = B[j]

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m; cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    long long dem = 0;
    int i = 0, j = 0;
    while (i < n && j < m){
        if (a[i] == b[j]) {
            int c1 = 0, c2 = 0;
            while (i < n && a[i] == b[j]){
                i++;
                c1++;
            }
            while (j < m && b[j] == a[i-1]){
                j++;
                c2++;
            }
            dem += 1ll * c1 * c2;
        }
        else if (a[i] > b[j]){
            j++;
        }
        else {
            i++;
        }
    }
    cout << dem << endl;
    
    return 0;
}