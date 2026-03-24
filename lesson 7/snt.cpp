#include <bits/stdc++.h>
using namespace std;
#define ll long long

int e = 1e6;

vector<bool> prime(e+5, true);
void sang(){
    prime[0] = prime[1] = false;
    int t = sqrt(e);
    for (int i = 2; i <= t; i++){
        for (int j = i * i; j <= e; j += i){
            prime[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sang();

    int n; cin >> n;
    int t = sqrt(n);
    int tong = 0;
    for (int i = 2; i <= n; i++ ){
        if (prime[i]){
            while (n % i == 0){
                tong++;
                n /= i;
            }
        }
    }

    cout << tong << endl;
    
    
    return 0;
}