// đếm xem 1 gia thừa của N có bao nhiêu chữ số 0 ở cuối cùng
/*
vì có số 0 ở cuối tức là * 10 tách ra là = 2 và 5. mà bậc của 2 luôn lớn hơn 5 => tìm bậc của 5 là đc

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n; cin >> n;
    ll ans = 0;
    while (n > 0){
        ans = (ans + n/5) % N;
        n /= 5;
    }
    cout << ans % N << endl;
    return 0;
}