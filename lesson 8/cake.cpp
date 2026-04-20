// https://docs.google.com/document/d/11Jx3R8E-6wzwRNGbNvULWtqEVU5-vWxc24ztkJZd63k/edit?tab=t.0
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const double PI = acos(-1.0);

bool check(double p[], int f, int n, double mid){
    if (mid <= 0) return true;
    int count = 0;
    for (int i = 0; i < n; i++){
        count += (int)(p[i]/mid);
    }
    return count >= f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,F; cin >> n >> F;
    int f = F + 1;
    int a[n];
    for (int &x : a){
        cin >> x;
    }
    double p[n];
    double max_area = -1e6;
    for (int i = 0; i < n; i++){
        p[i] = a[i] * a[i] * PI;
        max_area = max(max_area, p[i]);
    }

    double left = 0.0, right = max_area;
    double ans = -1;
    while (right - left > 1e-9){
        double mid = (left + right) / 2.0;
        if (check(p,f,n,mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }

    cout << fixed << setprecision(4) << left << endl;
    
    return 0;
}