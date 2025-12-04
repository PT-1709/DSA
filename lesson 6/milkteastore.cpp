/* có N thao tác, mỗi thao tác thêm vào cốc trà sữa 1g đường từ vị trí l -> r. sau đó những cốc có số gam đường >= k gam đường thì sẽ đạt chuẩn
để phục vụ khách hàng
có Q truy vấn, mỗi truy vấn in ra có bao nhiêu cốc đạt chuẩn từ vị trí L -> R
*/

#include <bits/stdc++.h>
using namespace std;

int a[300000], d[300000]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,K,Q; cin >> N >> K >> Q;//
    while (N--){
        int l,r; cin >> l >> r;
        d[l] += 1;
        d[r + 1] -= 1;     
    }
    for (int i = 1; i <= 200000; i++){
        if (i == 1){
            a[i] = d[i];
        }
        else a[i] = a[i-1] + d[i];
    }
    while (Q--){
        int l, r; cin >> l >> r;
        int dem = 0;
        for (int i = l; i <= r; i++){
            if (a[i] >= K){
                dem++;
            }
        }
        cout << dem << endl;
    }

    
    return 0;
}