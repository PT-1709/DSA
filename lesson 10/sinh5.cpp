// tìm số lớn hơn mà nhỏ nhất là hoán vị của số hiện tại
// B1: duyệt từ gần cuối về đầu, kiểm tra xem số đầu tiên nào bé hơn tk đứng sau nó ví dụ a[i] < a[i+1]
// B2: tìm đc tk bé nhất mà lớn hơn tk đầu tiên đó rồi đổi chỗ cho 2 tk vs nhau
// B3: sắp xếp theo thứ tự tăng dần những tk còn lại sau khi hoán đổi

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; cin >> s;

    int n = (int)s.size() - 2;

    while (n >= 0 && s[n] > s[n+1]){
        --n;
    }
    if (n < 0){
        cout << s << endl;
        return 0; 
    }
    int min_val = s[n+1];
    int pos = 1000;
    for (int i = n+1; i <= (int)s.size(); i++){
        if (s[i] - '0' > s[n] - '0' && s[i] - '0' <= min_val ){
            min_val = s[i] - '0';
            pos = i;
        }
    }
    
    swap(s[n], s[pos]);
    sort(s.begin()+ n+1, s.end());
    
    cout << s;
    
    return 0;
}