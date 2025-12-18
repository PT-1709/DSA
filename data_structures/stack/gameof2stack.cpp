#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    if (!(cin >> tc)) return 0;
    while (tc--) {
        int n1, n2;
        ll x;
        cin >> n1 >> n2 >> x;
        vector<ll> a(n1), b(n2);
        for (int i = 0; i < n1; ++i) cin >> a[i];
        for (int i = 0; i < n2; ++i) cin >> b[i];

        // Build stacks so that top() = first element in input (the "top" of the stack)
        stack<ll> s1, s2;
        for (int i = n1 - 1; i >= 0; --i) s1.push(a[i]);
        for (int i = n2 - 1; i >= 0; --i) s2.push(b[i]);

        stack<ll> takenA; // lưu các phần tử đã lấy từ s1 để có thể trả lại
        ll sum = 0;
        int taken = 0;
        // Lấy tối đa từ s1 ban đầu
        while (!s1.empty() && sum + s1.top() <= x) {
            sum += s1.top();
            takenA.push(s1.top());
            s1.pop();
            ++taken;
        }
        int ans = taken;

        // Lần lượt lấy từ s2; khi vượt x thì trả lại dần phần từ takenA (tức bỏ bớt từ s1)
        while (!s2.empty()) {
            ll v = s2.top();
            s2.pop();
            sum += v;
            ++taken;

            while (sum > x && !takenA.empty()) {
                sum -= takenA.top();
                // trả lại vào s1 (không nhất thiết cần thiết cho kết quả, nhưng giữ cấu trúc)
                s1.push(takenA.top());
                takenA.pop();
                --taken;
            }

            if (sum > x && takenA.empty()) {
                // Không thể giảm được nữa, dừng
                break;
            }
            ans = max(ans, taken);
        }

        cout << ans << '\n';
    }
    return 0;
}