#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    queue <int> q;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        q.push(x);
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}