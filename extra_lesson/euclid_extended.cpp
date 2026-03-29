// nghịch đảo a của module m
// khi dùng phép thương trong đồng dư thì có thể nhân với nghịch đảo của số đó với mod mà đề bài cho
// idea nhìn vào ảnh


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll euclid_extendted( ll a, ll m){
    if (a % m == 1) return 1;
    // khởi tạo vị trí, với mod đc đứng trên so với số a
    ll r_prev2 = m, r_prev1 = a;
    // ax + by = 1
    ll y_prev2 = 1, y_prev1 = 0;
    ll x_prev2 = 0, x_prev1 = 1;

    if (a % m == 0) {
        return -1;
    }

    while (r_prev1 != 0){
        // tính thương và số dư mới
        ll q_i = r_prev2 / r_prev1;
        ll r_i = r_prev2 % r_prev1;

        // tính hệ số y và x
        ll y_i = y_prev2 - q_i* y_prev1;
        ll x_i = x_prev2 - q_i* x_prev1;

        // kiểm tra nếu r_i = 1 thì tức là đã tìm thấy
        if (r_i == 1){
            if (x_i < 0){
                return x_i + m;
            }
            return x_i;
        }

        
        // gán lại để làm vòng lặp mới
        r_prev2 = r_prev1, r_prev1 = r_i;
        y_prev2 = y_prev1, y_prev1 = y_i;
        x_prev2 = x_prev1, x_prev1 = x_i;

    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, m; cin >> a >> m;
    cout << euclid_extendted(a,m) << endl;
    
    return 0;
}