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
    int first_sum = 0;
    for (int i = 0; i < k; i++){
        first_sum += a[i];
    }
    int last_sum = first_sum;
    int p = 0;
    for (int i = 1; i <= n - k; i++ ){
        last_sum = last_sum - a[i-1] + a[i + k - 1];
        if (last_sum > first_sum){
            first_sum = last_sum;
            p = i;
        }
    }
    cout << p << " " << first_sum << endl;
    for (int i = 0; i <k; i++){
        cout << a[p+i] << " ";
    }
    
    
    return 0;
}