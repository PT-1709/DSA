// in ra số lớn nhất và bé nhất có trong cửa sổ
/*
8 2
8 5 8 6 7 6 5 8

5 8
5 8
6 8
6 7
6 7
5 6
5 8

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    multiset <int> ms;
    for (int i = 0; i < k; i++){
        ms.insert(a[i]);
    }
    multiset <int>:: iterator it1 = ms.begin();// vì nó đang sắp xếp theo tăng dần có thể gán
    multiset <int>:: reverse_iterator it2 = ms.rbegin();// đối với rbegin() thì phảu có reverse để nó mới hiểu là phần tử cuối cùng

    cout << *it1 << " " << *it2 << endl;
    ms.erase(a[0]);

    for (int i = 1; i <= n- k; i++){
        ms.insert(a[i+k-1]);
        auto t1 = ms.begin();
        auto t2 = ms.rbegin();
        cout << *t1 << " " << *t2 << endl;
        ms.erase(a[i]);
    }
    
    
    return 0;
}