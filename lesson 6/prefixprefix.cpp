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

#include <bits/stdc++.h>
using namespace std;

struct query{
    int l,r,d;
};

query A[1000005];// mảng lưu tao tác
int F[1000005]; // mảng cộng dồn lưu thao tác , mảng tần số 
int a[1000005]; // mảng a cho trước
int d[1000005];// mảng hiệu của a
int D[1000005]; // mảng hiệu của A

int main(){
    int n,m,k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> A[i].l >> A[i].r >> A[i].d;
    }
    while (k--){
        int l,r; cin >> l >> r;
        D[l] += 1;
        D[r +1 ] -= 1;
    }

    for (int i = 1; i <= m; i++){
        if(i== 1) F[i] = D[i];
        else F[i] = F[i-1] + D[i];
    }
    
    for (int i = 1; i <= n; i++){
        if (i == 1) d[i] = a[i];
        else d[i] = a[i] - a[i-1];
    }
    
    for (int i = 1; i <= m; i++){
        d[A[i].l] += F[i] * A[i].d;
        d[A[i].r + 1] -= F[i] * A[i].d;
    }

    int tong = 0;
    for (int i = 1; i <= n; i++){
        tong += d[i];
        cout << tong << " ";
    }
    return 0;
}