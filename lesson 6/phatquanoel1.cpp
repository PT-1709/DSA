// có N món quà với khối lượng khác nhau, PT muốn nhận đc về nhiều quà nhất nhưng túi của PT chỉ có max = S, xác định xem số lượng
// quà mà PT có thể lấy nhưng những món quà đó phải ở cạnh nhau
/*
11 10
3 5 2 1 4 2 1 8 9 3 7

5

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,s; cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    
    int right = 0, left = 0, tong = 0, res = 0;
    
    for (; right < n ;right++){
        tong += a[right];
        while (tong > s ){
            tong -= a[left];
            left++;
        }
        res = max(res, right-left+1); 
    }

    cout << res << endl;
    
    return 0;
}