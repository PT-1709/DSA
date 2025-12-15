// https://www.hackerrank.com/challenges/game-of-two-stacks/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >>tc;
    while (tc--){
        stack <int> tmp1,tmp2;
        int n1,n2, maxSum; cin >> n1 >> n2 >> maxSum;
        for(int i = 0; i < n1; i++){
            int x; cin >> x;
            tmp1.push(x);
        }
        for(int i = 0; i < n2; i++){
            int x; cin >> x;
            tmp2.push(x);
        }
        stack <int> st1,st2;
        while (!tmp1.empty()){
            st1.push(tmp1.top());
            tmp1.pop();
        }
        while (!tmp2.empty()){
            st2.push(tmp2.top());
            tmp2.pop();
        }
        // th1: check stack 1
        int dem1 = 0;
        ll sum1 = 0;
        vector<int> vt1;
        while (sum1 < maxSum){
            sum1 += st1.top();
            vt1.push_back(st1.top());
            dem1++;
            st1.pop();
        }
        for (auto it = vt1.rbegin(); it != vt1.rend(); it++){
            st1.push(*it);
        }
        // th2: check stack 2
        int dem2 = 0;
        ll sum2 = 0;
        vector <int> vt2;
        while (sum2 < maxSum){
            sum2 += st2.top();
            vt2.push_back(st2.top());
            dem2++;
            st2.pop();
        }
        for (auto it = vt2.rbegin(); it != vt2.rend(); it++){
            st2.push(*it);
        }
        //th3: check 2 stack
        int dem3 = 0;
        ll sum3 = 0;
        while (sum3 < maxSum){
            if (sum3 < maxSum && st1.top() > st2.top()){
                if (sum3 + st1.top() <= maxSum){
                    sum3 += st1.top();
                    dem3++;
                    st1.pop();
                }
            }
            else if (sum3 < maxSum && st1.top() <= st2.top()){
                if (sum3 + st2.top() <= maxSum){
                    sum3 += st2.top();
                    dem3++;
                    st2.pop();
                }
            }

        }
    }
    
    return 0;
}