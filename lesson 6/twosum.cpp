// làm theo 3 cách: binarysearch - two-pointers - map
// cho dãy a và số k, tìm cặp i - j sao cho a[i] + a[j] = k, ko có thì -1

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector <int> l(n1);
    vector <int> r(n2);
    for (int i = 0; i < n1; i++){
        l[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++){
        r[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (l[i] < r[j]){
            a[k] = l[i];
            i++;
        }
        else{
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < n2){
        a[k] = r[j];
        j++;
        k++;
    }
}


void mergesort(vector <int> &a, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

bool check (vector <int> a, int target){
    
    int i = 0, j = a.size() - 1;
    while (i <= j){
        int mid = (i + j) / 2;
        if (a[mid] == target){
            return true;
        }
        else if (a[mid] < target){
            i = mid + 1;
        }
        else{
            j = mid - 1;
        }
    }
    return false;
}

/*
6 23
1 1 5 6 19 20 

*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    mergesort(a,0, n-1);
    
    int i = 0, j = n- 1;
    while (i < j){
        if (a[i] + a[j] == k){
            cout << i << " " << j << endl;
            return 0;
        }
        else if (a[i] + a[j] > k){
            j--;
        }
        else i++;
    }
    cout << "-1" << endl;
    // tìm kiếm nhị phân 
    /*for (int i = 0; i < n; i++){
        if (check(a, k - a[i])){
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";*/

    
    
    return 0;
}