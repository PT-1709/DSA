// tìm xem có ít nhất bao nhiêu cách di chuyển để có k số liên tiếp là 1
/*
1 1 0 1 0 0 0 1 0 0 1

n = 11 k = 4
thì chỉ cần 1 tk di chuyển vào số 0 đầu tiên để hoàn thành
đầu tiên là tìm ra dãy con có số 1 nhiều nhất
*/

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
    int sum = 0;
    for (int i = 0; i < k; i++){
        sum += a[i];
    }
    int t = 0;
    int max_sum = sum;
    for (int i = 1; i <= n- k; i++){
        max_sum = max_sum - a[i-1] + a[i+k-1];
        if (max_sum > sum){
            sum = max_sum;
            t = i +k;
        } 
    }


    int dem = 0; 
    for (int i = t; i < n; i++){
        if (a[i] == 1){
            dem++;
        }
    }

    if (dem < k - sum){
        cout << "-1"<< endl;
        return 0;
    }
    cout << k - sum << endl;
    
    return 0;
}