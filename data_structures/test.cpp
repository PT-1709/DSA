#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    public:
        int largestRectange(vector<int> v){
            int n = v.size() - 1;
            ll max_area = 0;
            stack<pair<int,int>> st;
            for (int i = 0; i <= n; i++){
                if (st.empty() || v[i] > st.top().first){
                    st.push({v[i],i});
                }
                else if ( v[i] <= st.top().first){
                    int pos = i;
                    while (!st.empty() && v[i] <= st.top().first){
                        pair <int,int> top_pair = st.top();
                        ll current_area = (i - top_pair.second) * top_pair.first;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sl;
    int n; cin >> n;
    vector <int> v(n+1,0);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        v[i] = x;
    }
    cout << sl.largestRectange(v) << '\n';
    
    return 0;
}