// đếm xem trong mảng có bao nhiêu dãy con có tổng <= S
// tổng dãy con = right - left + 1

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

    int tong = 0, right = 0, left = 0, cnt = 0;
    for (; right < n; right++){
        tong += a[right];
        while (tong > s){
            tong -= a[left];
            left++;
        }
        cnt += right - left + 1;
    }

    cout << cnt << endl;
    
    return 0;
}