// cho dãy số n phần tử và số k, tìm dãy con k phẩn tử sao cho tổng dãy con này lớn nhất
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int tong = 0, max_sum = 0;
    for (int i = 0; i < k; i++){
        tong += a[i];
    }


    max_sum = tong;
    for (int i = 1; i <= n-k; i++){
        max_sum = max_sum - a[i -1] + a[i +k + 1];
        if (max_sum > tong){
            tong = max_sum;
        }
    }

    cout <<  tong << endl;
    
    return 0;
}