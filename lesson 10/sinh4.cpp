// // cho N và K lấy tổ hợp chập K của N và cho sẵn 1 tổ hợp, theo thứ tự ngược thì tổ hợp đó đứng vị trí bao nhiêu
// ý tưởng: sinh xâu ra và vứt vào vector, rồi duyệt ngược từ cuối về đầu để xem nó đứng thứ mấy
// tổ hợp là xét có thứ tự, những bộ lấy rồi k đc lấy lại như 123 ko đc lấy là 321 132, ncl nó phải có thứ tự tăng dần

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int X[1000], n,k, A[1000], final = 0;

void ktao(){
    for (int i = 1; i <= k; i++){
        X[i] = i;
    }
}

void sinh(){
    int i = k; 
    while (i >= 1 && X[i] == n - k + i){
        --i;
    }
    if (i == 0){
        final = 1;
    }
    else{
        X[i]++;
        for (int j = i + 1; j <= k; j++){
            X[j] = X[j-1] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        cin >> A[i];
    }

    ktao();
    vector<vector<int>> res;
    while (final == 0){
        vector <int> tmp (X+1, X+k+1);
        res.push_back(tmp);
        sinh(); 
    }
    int dem = 0;
    for (int i = (int)res.size() - 1; i >= 0; i--){
        ++dem;
        bool check = true;
        for (int j = 1; j <= k; j++){
            if (res[i][j-1] != A[j]){
                check = false;
                break;
            }
        }

        if (check){
            cout << dem << endl;
            return 0;
        }
    }
    
    return 0;
}