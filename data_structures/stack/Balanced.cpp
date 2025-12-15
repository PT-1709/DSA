#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(string s){
    stack <char> st;
    for (char c : s){
        if (c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else{
            if (st.empty()){
                return false;
            }
            char topStack = st.top();
            if ( c == ')' && topStack == '(' || c == '}' && topStack == '{' || c== ']' && topStack == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    while (tc--){
        string s; cin >> s;
        //cin.ignore();
        if (check(s)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}