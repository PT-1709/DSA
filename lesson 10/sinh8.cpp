// Hàm sinh ra hoán vị kế tiếp có sẵn trong c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a[] = {3,1,4,5,7,9,8,2,6};
    next_permutation(a,a+9);
    for (int x : a){
        cout << x << " ";
    }
    
    return 0;
}