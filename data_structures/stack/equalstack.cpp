// https://www.hackerrank.com/challenges/equal-stacks/problem?isFullScreen=true
/*
5 3 4
3 2 1 1 1 
4 3 2
1 1 4 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack <int> tmp1, tmp2, tmp3;
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    int tong1 = 0, tong2 = 0, tong3 = 0;
    for (int i = 0; i < n1; i++){
        int x; cin >> x;
        tong1 += x;
        tmp1.push(x);
    }
    for (int i = 0; i < n2; i++){
        int x; cin >> x;
        tong2 += x;
        tmp2.push(x);
    }
    for (int i = 0; i < n3; i++){
        int x; cin >> x;
        tong3+=x;
        tmp3.push(x);
    }

    stack <int> st1, st2, st3;
    while (!tmp1.empty()){
        st1.push(tmp1.top());
        tmp1.pop();
    }
    while (!tmp2.empty()){
        st2.push(tmp2.top());
        tmp2.pop();
    }
    while (!tmp3.empty()){
        st3.push(tmp3.top());
        tmp3.pop();
    }

    while(true){
        if (tong1 == tong2 && tong2 == tong3){
            cout << tong1 << '\n';
            return 0;
        }

        if (st1.empty() || st2.empty() || st3.empty()){
            cout << "0\n";
            return 0; 
        }

        int max_sum = max({tong1,tong2,tong3});
        if (tong1 == max_sum){
            tong1 -= st1.top();
            st1.pop();
        }
        else if (tong2 == max_sum){
            tong2 -= st2.top();
            st2.pop();
        }
        else if (tong3 == max_sum){
            tong3 -= st3.top();
            st3.pop();
        }
    }
    return 0;
}