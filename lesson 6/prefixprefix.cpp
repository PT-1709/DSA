/* mảng a có N phần tử và có M thao tác, mỗi thao tác yêu cầu tăng chỉ số từ L đến R lên D đơn vị. Sau đó, có K truy vấn,
mỗi truy vấn nhập nhập x và y (1 <= x <= y <= M) lặp lại thao tác từ x -> y thêm 1 lần nữa. cuối cùng in ra mảng .

ý tưởng: tạo ra struct và mảng struct để lưu các thao tác.
tính mảng hiệu để tìm ra số lần truy vấn x -> y đc thực hiện
sau đó chỉ cần tính 1 lần mảng hiệu nữa để tìm ra dãy số => d[i] = d[i-1] + D * số lần

6 5 2
1 7 5 2 8 7
2 6 5
1 5 1
1 6 1
2 6 4
2 5 4
2 5
2 4



*/

int a[100005]; // a lưu dãy số cho trc
struct query{
    int l,r,d;
};
int D[100005], F[100005];   // D là mảng hiệu của số thao tác đc gọi, F là mảng cộng dồn để tính ra tần suất của các thao tác
query b[100005];
int d[100005], f[100005]; // d là mảng hiệu của a

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++){
        cin >> b[i].l >> b[i].r >> b[i].d; // lưu l r d vào mảng  struct
    }

    while (k--){
        int l,r; cin >> l >> r;// tính mảng hiệu
        D[l] += 1;
        D[r +1] -= 1; 
    }

    for (int i = 1; i <= m; i++){ // tính lại mảng cộng dồn
        if (i == 1) F[i] = D[i];
        else F[i] = F[i-1] + D[i];
    }
    
    for (int i = 1; i <=n ; i++){  // tính mảng hiệu của mảng ban đầu
        if ( i == 1) d[i] = a[i];
        else d[i] = a[i] - a[i-1]; 
    }

    for (int i = 1; i <= m; i++){ // tính lại mảng cộng dồn sau khi có D mảng tần số của thao tác và F là số lần thao tác đó đc lặp lại
        if (F[i] != 0){
            d[b[i].l] += b[i].d * F[i];
            d[b[i]. r + 1] -= b[i].d * F[i];
        }
    }
    int tong = 0;
    for (int i = 1; i <= n; i++){ // tính lải mảng sau khi đc thêm các thao tác
        tong += d[i];
        cout << tong << " ";
    }
    
    
    return 0;
}
// đến 42 : 44