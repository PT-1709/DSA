// cho 2 mảng đã sx tăng dần, với mỗi phần tử mảng B có bao nhiêu phần tử mảng A bé hơn
/*
6 7
2 3 6 6 6 8
5 5 5 6 6 7 10

2 2 2 2 2 5 6
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m; cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int i = 0, j = 0;
    while (i < n && j < m){
        if (a[i] < b[j]){
            i++;
        }
        else{
            cout << i << " ";
            j++;

        }
    }
    while (j < m){
        cout << n << " ";
        j++;
    }
    return 0;
}