#include <bits/stdc++.h>
using namespace std;

int a[505][505];
int n,m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};



bool check(int i, int j){
    for (int k =0; k < 8; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1  && i1 <= n && j1 >= 0 && j1 <= m && a[i][j] < a[i1][j1]){
            return false;
        }
        
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int dem = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (check(i,j)){
                dem++;
            }
        }
    }

    cout << dem << endl;
    
    return 0;
}