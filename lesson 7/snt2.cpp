// làm 1 bài về đếm ước của 1 số phân tích ra thừa số nguyên tố
// ta có N = p1^a1 * p2^a2 * .... thì số ước là (a1 + 1) * (a2 + 1) * ....
// bài này ko thể sài SPF vì quá dài vs cả chỉ yêu cầu 1 số duy nhất -> sàng nguyên tố đến max 1e6 và còn lại sẽ là 1 số nguyên tố vì ko thể
// chia đc nữa

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N = 1e6;
vector <bool> prime(N+ 1 , true);
vector <int> isprime;

void sang(){
    prime[0] = prime[1] = false;
    for (int i = 2; i <= N; i++){
        if (prime[i]){
            for (ll j = (ll)i * i ; j <= N; j+= i){
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
        if (p * p >n){
            break;
        }
        int cnt = 0;
        while (n % p == 0){
            cnt++;
            n/= p;
        }
        if (cnt > 0){
            ans *= (cnt + 1);
        }
        cnt = 0;
    }

    if (n > 1){
        ans *= 2;
    }

    cout << ans << endl;
    
    
    return 0;
}