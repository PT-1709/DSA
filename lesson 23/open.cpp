#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    /*
    stack
    push(x) - pop(x) - size() - empty() - top()
    
    queue
    push(x) - front() - pop() - back() - size() - empty()

          priority_queue<int> Q: Luôn mặc định top là tk lớn nhất
    nếu : priority_queue<int, vector<int>,greater<int>> Q; lúc này mặc định tk top luôn bé nhất
    */
    priority_queue<int> Q;
    Q.push(3); Q.push(1);
    Q.push(2); Q.push(4);
    cout << Q.top() << endl; // 4
    Q.pop(); // xoa 4
    Q.push(0); Q.push(5);
    cout << Q.top() << endl;
    
    return 0;
}