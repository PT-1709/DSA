// sinh ra sâu nhị phân kết tiếp, nếu là sâu nhị phân cuối cùng thì sinh ra sâu nhị phân đầu tiên
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; cin >> s;
    int i = (int)s.size() - 1;
    while (i >= 0 && s[i] == '1'){
        s[i] = '0';
        --i;
    }
    if (i != -1){
        s[i] = '1';
    }
    cout << s << endl;
    
    
    
    return 0;
}