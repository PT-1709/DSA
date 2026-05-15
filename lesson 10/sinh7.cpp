// cho N và đc cung cấp 1 hoán vị, yêu cầu sinh ra hoán vị tiếp theo, nếu là hoán vị cuối cùng thì in ra hoán vị đầu tiên
// tìm số đầu tiên từ phải qua trái bé hơn số đứng sau nó, A[i] < A[i+1]

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin >> N;
    int X[N];
    for (int i = 0; i < N; i++){
        cin >> X[i];
    }
    string s;
    for (int x : X){
        s += char(x + '0');
    }

    int n = (int)s.size() - 2;

    while (n >= 0 && s[n] > s[n+1]){
        --n;
    }
    if (n < 0){
        for (int i = 1; i <= N; i++){
            cout << i << " ";
        }
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
    
    for(char c : s){
        cout << c << " ";
    }
    
    return 0;
}