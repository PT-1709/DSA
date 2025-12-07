
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        deque<int> dq; // lưu chỉ số
        vector<int> result;

        for (int i = 0; i < N; i++) {
            // Loại bỏ phần tử ra khỏi cửa sổ
            if (!dq.empty() && dq.front() <= i - K) {
                dq.pop_front();
            }

            // Loại bỏ phần tử nhỏ hơn arr[i] ở cuối deque
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Khi đủ K phần tử, lấy max
            if (i >= K - 1) {
                result.push_back(arr[dq.front()]);
            }
        }

        // In kết quả
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}

// ko hieeru code nay