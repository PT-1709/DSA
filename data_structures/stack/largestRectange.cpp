// https://www.hackerrank.com/challenges/largest-rectangle/problem?isFullScreen=true
// https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector <int> v(n+1,0);
    for (int i = 0; i  < n; i++){
        int x; cin >> x;
        v[i] = x;
    }
    ll max_area = 0;
    stack <pair<int,int>> st;
    for (int i = 0; i <= n; i++){   
        if (st.empty() || v[i] >st.top().first){
            st.push({v[i],i});
        }
        else if (v[i] <= st.top().first){
            int pos = i;
            while (!st.empty() && v[i] <= st.top().first){
                pair <int,int> top_pair = st.top();
                ll current_area = (ll)(i - top_pair.second) * top_pair.first;
                if (max_area < current_area){
                    max_area = current_area;
                }
                pos = top_pair.second;
                st.pop();
            }
            st.push({v[i], pos});
        }
    }
    cout << max_area << '\n';
    
    return 0;
}
/*
leetcode, use class
class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        v.push_back(0);
        int n = v.size() - 1;
        stack <pair<int,int>> st;
        long long max_area = 0;
        for (int i = 0; i <= n; i++){
            if (st.empty() ||  v[i] > st.top().first){
                st.push({v[i],i});
            }
            else if (v[i] <= st.top().first){
                int pos = i;
                while (!st.empty() && v[i] <= st.top().first){
                    pair<long long, long long> top_pair = st.top();
                    long long current_area = (i - top_pair.second) * top_pair.first;
                    if (max_area < current_area){
                        max_area = current_area;
                    }
                    pos = top_pair.second;
                    st.pop();
                }
                st.push({v[i], pos});
            }
        }
        return max_area;
    }
};
*/