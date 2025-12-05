// sắp xếp 2 mảng tăng dần, sử dụng 2 con trỏ

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m; cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<int> c;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;
        }
        k++;
    }
    while (i < n){
        c.push_back(a[i]);
        i++;
        k++;
    }
    while (j < m){
        c.push_back(b[j]);
        j++;
        k++;
    }
    for (int x : c){
        cout << x << " ";
    }
    return 0;
}