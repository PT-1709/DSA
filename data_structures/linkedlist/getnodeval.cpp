// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true
// sử dụng 2 con trỏ, cho 1 con trỏ chạy trước k bước, khi mà 1 con trỏ đến nullptr thì còn trỏ còn lại cách nullptr = k
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node* next;
};

typedef struct Node* node;

node MakeNewNow(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

void insertLast(node &a, node & tail,int x){
    node tmp = MakeNewNow(x);
    if (a == nullptr){
        a = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tmp;
    }
}

void in(node a){
    while (a != nullptr){
        cout << a->data << " ";
        a = a->next;
    }
    cout << '\n';
}

int getNode(node a, int k){
    node fast = a;
    for (int i = 0; i < k; i++){
        fast = fast->next;
    }
    node slow = a;
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

void deleteNode(node &a){
    while (a != nullptr){
        node tmp = a;
        a = a->next;
        delete tmp;
    }
    a = nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    while (tc--){
        node a = nullptr;
        node tail = nullptr;
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            insertLast(a,tail,x);
        }
        int k; cin >> k;
        cout << getNode(a,k) << '\n';
        deleteNode(a);
    }
    
    return 0;
}