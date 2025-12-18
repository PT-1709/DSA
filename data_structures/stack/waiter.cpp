// http://hackerrank.com/challenges/waiter/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int e = 1e6;
vector <bool> prime(e+1, true);
void check(){
    prime[0] = prime[1] = false;
    int n = sqrt(e);
    for (int i = 0; i < n; i++){
        if (prime[i]){
            for (int j = i * i; j <= e; j += i){
                prime[j] = false;
            }
        }
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    check();
    int n, q; cin >> n >> q;
    vector <int> vt;
    for (int i = 2; i <= e; i++){
        if (prime[i]){
            vt.push_back(i);
            if (vt.size() == q){ // vt is vector save the snt
                break;
            }
        }
    }
    
    stack <int> st;
    for (int i = 0; i < n ; i++){
        int x; cin >> x;
        st.push(x); // add to stack
    }

    for (int i = 0; i < q; i++){
        stack<int> b; // stack b when % == 0
        stack <int> a_temp;
        int p = vt[i];

        while (!st.empty()){
            int x = st.top();
            st.pop();
            if (x % p == 0){
                b.push(x);
            }
            else{
                a_temp.push(x);
            }
        }
        while (!b.empty()){
            cout << b.top() << '\n';
            b.pop();
        }
        st = a_temp;
    }
    while (!st.empty()){
        cout << st.top() << '\n';
        st.pop();
    }
    
    return 0;
}