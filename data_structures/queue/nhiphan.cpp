#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sinhNhiPhan(int n){
    queue <string> q;
    q.push("1");
    while (n--){
        string s1 = q.front(); // lấy tk đầu tiên của hàng đợi
        q.pop(); // xoá đi
        cout << s1 << " "; // in ra 
        string s2 = s1; // gán
        q.push(s1 + '0');// tk tiếp theo là tk trc + 0
        q.push(s2 + '1'); // tk tiếp là tk trc + 1
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    sinhNhiPhan(n);
    
    return 0;
}