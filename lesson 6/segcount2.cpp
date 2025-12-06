// cho mảng a gồm n số và s là tổng, hỏi có bao nhiêu mảng con liên tiếp  mà tổng các phần tử >= s

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s; cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int left = 0, right = 0, tong = 0, cnt = 0;
    for (; right < n; right++){
        while (tong >= s){
            cnt += n - right;
            tong -= a[left];
            left++;
        }

    }
    cout << cnt << endl;
    
    return 0;
}