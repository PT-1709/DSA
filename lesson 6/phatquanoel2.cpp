// có N món quà với khối lượng khác nhau, PT muốn nhận đc về ít quà nhất nhưng túi của PT chỉ có max = S, xác định xem số lượng
// quà mà PT có thể lấy nhưng những món quà đó phải ở cạnh nhau
/*
14 14
4 4 5 1 3 1 3 4 1 1 5 4 1 4

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
    
    int left = 0, right = 0, tong = 0, res = INT_MAX;
    for (;right < n; right++){
        tong += a[right];
        while (tong >= s){
            res = min(res,right - left + 1);
            tong -= a[left];
            left++;
            
        }
        
    }

    cout << res << endl;
    
    return 0;
}