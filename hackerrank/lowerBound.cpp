#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector <int> v(n+1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    int tc; cin >> tc;
    while (tc--){
        int t; cin >> t;
        auto it = lower_bound(v.begin(), v.end(), t);
        int it2 = *it;
        if (t == it2){
            cout << "Yes " << distance(v.begin(), it) << endl; // distance để đo vị trí từ đầu tới hiện tại
        }
        else{
            cout << "No " << distance(v.begin(), it) << endl;
        }
    }
    
    return 0;
}