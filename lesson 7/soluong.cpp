// đếm xem N! có bao nhiêu ước
// dùng legendre để đế xem bậc cao nhất của 1 số nguyên tố rồi dùng công thức (p1 +1) * ... * (pn + 1) để tính ra số ước

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

int N = 1e5;
vector <bool> prime(N+5, true);
vector <int> isprime;

void sang(){
    for (int i = 2; i * i <= N; i++){
        if (prime[i]){
            for (int j = i * i; j <= N; j+= i){
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++){
        if (prime[i]){
            isprime.push_back(i);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sang();
    

    ll n; cin >> n;
    ll ans = 1;
    for (int p : isprime){
        if (p > n){
            break;
        }
        ll cnt = 0;
        ll tmp = n;
        while (tmp > 0){
            cnt = (cnt + (tmp/p));
            tmp /= p;
        }
        ans = ans * (cnt + 1) % mod;
    }

    cout << ans % mod << endl;
    
    return 0;
}