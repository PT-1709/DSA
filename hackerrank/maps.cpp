#include <bits/stdc++.h>
using namespace std;
/*
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

30
20
0
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<string,int> mp;
    int q; cin >> q;
    while (q--){
        int type; cin >> type;
        switch(type){
            case 1:{
                string s; cin >> s;
                int d; cin >> d;
                auto it = mp.find(s);
                if (it == mp.end()){
                    mp[s] = d;
                }
                else{
                    int t = mp[s] + d;
                    mp[s] = t;
                }
                break;
            }
            case 2:{
                string s; cin >> s;
                auto it = mp.find(s);
                if (it != mp.end()){
                    mp.erase(s);
                }
                break;
            }
            case 3:{
                string s; cin >> s;
                auto it = mp.find(s);
                if (it != mp.end()){
                    cout << mp[s] << endl;;
                }
                else{
                    cout << "0" << endl;;
                }
                break;
            }
        }
    }
    
    return 0;
}