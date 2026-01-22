// cho mảng a gồm N phần tử  và số nguyên K, hãy tìm median của mọi dãy con liên tiếp cỡ K của mảng A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// code ngây thơ
/*int sotrave(vector <int> t, int k){
    sort(t.begin(), t.end());
    int vitri = ((k-1)/2)+1;
    return t[vitri - 1];
}

void giai_quyet(vector <int> v, int n, int k ){
    vector <int> t;
    for (int i = 1; i <= k; i++){
        t.push_back(v[i]);
    }
    for (int i = 1; i <= n - k + 1; i++){
        cout << sotrave(t,k) << " ";
        if (i+k <= n){
            t.push_back(v[i+k]);
            t.erase(t.begin());
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin >> n >>k;
    vector<int> v(n+2);
    for (int i = 1; i <= n; i++) cin >> v[i];
    
    giai_quyet(v,n,k);
    
    return 0;
}*/ 

// code sử dụng multiset + iterator để làm nếu chẵn thì lấy số ở giữa theo công thức

/*#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin >> n >> k;
    int a[N];
    for (int i = 1; i <= n; i++) cin >> a[i];

    multiset<ll> ms;
    for (int i = 1; i <= k; i++){
        ms.insert(a[i]);
    }
    
    multiset<ll> :: iterator it = ms.begin();
    int x = (k-1) / 2;
    advance(it,x);
    cout << *it << " ";

    for (int i = k+1; i <= n; i++){
        ms.insert(a[i]);
        if (a[i] < *it){
            it--;
        }
        if (a[i - k] <= *it){
            it++;
        }
        multiset <ll> :: iterator it1 = ms.find(a[i-k]);
        ms.erase(it1);
        cout << *it << " ";
    }
    
    return 0;
}*/

// vẫn là cách tối ưu nhưng nếu k chẵn thì lấy số TBC của 2 số giữa
#include <bits/stdc++.h>
using namespace std;
#define ll long long



vector<double> vectrave(vector<int> nums, int k){
    vector <double> ans;
    int n = nums.size();
    multiset<ll> ms;
    for (int i = 0; i < k; i++){
        ms.insert(nums[i]);
    }
    int x = (k-1) / 2;
    auto it  = ms.begin();
    advance(it,x);

    if (k % 2 == 0){
        double t = (*it + *next(it)) / 2.0;
        ans.push_back(t);
    }
    else{
        ans.push_back(*it);
    }

    for (int i = k; i < n; i++){
        ms.insert(nums[i]);
        if (nums[i] < *it){
            it--;
        }

        if (nums[i-k] <= *it){
            it++;
        }

        ms.erase(ms.find(nums[i-k]));
        if (k % 2 == 0){
            double t = (*it + *next(it)) / 2.0;
            ans.push_back(t);
        }
        else{
            ans.push_back(*it);
        }
    }
    return ans;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector <int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    vector <double> ans = vectrave(nums, k);
    for (auto it : ans){
        cout << it << " ";
    }
    return 0;
}