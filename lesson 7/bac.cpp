/* bậc của thừa số nguyên tố trong n!
 cho số tự nhiêu N và số nguyên tố p. Nhiệm vụ là tìm ra x lớn nhất để
 N chia hết chia p^x
 tìm ra xem có bao nhiêu số là bội của số nguyên tố đó rồi bội đó có bao 
 số nguyên tố p rồi cộng tất cả số đó lại là ra
 công thức legendre
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, p; cin >> n >> p;
    ll ans = 0;
    for (ll i = 1; i <= n; i++){
        ans += n / (pow(p,i));
    }

    cout << ans << endl;
    
    return 0;
}