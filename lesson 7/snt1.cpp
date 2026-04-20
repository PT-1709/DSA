// in ra thừa số nguyên tố của 2 -> N, dùng spf (smallest prime factor) để sử dụng thay vì sài sàng nguyên tố bình thường

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100000;
int spf[MAXN + 1];

void setup(){
    for (int i = 1; i <= MAXN; i++){
        spf[i] = i;
    }

    // là 1 phiên bản sàng nâng cao hơn
    for (int i = 2; i * i <= MAXN ; i++){
        if (spf[i] == i){
            for (int j = i * i; j <= MAXN; j+= i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void fc(int n){
    while (n > 1){
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    setup();

    int n; cin >> n;
    for (int i = 2; i <= n; i++){
        cout << i << ": ";
        fc(i);
        cout << '\n';
    }
    
    
    return 0;
}