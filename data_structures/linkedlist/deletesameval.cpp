// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem?isFullScreen=true

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

void deleteNode(node &a){
    while (a != nullptr){
        node tmp = a;
        a = a->next;
        delete tmp;
    }
    a = nullptr;
}

void xoanode(node &a){
    node fast = a->next;
    node slow = a;
    while (fast != nullptr){
        if (fast->data == slow->data){
            node tmp = fast;
            slow->next = fast->next;
            fast= slow->next;
            delete tmp;
        }
        else{
            slow = fast;
            fast= fast->next;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        node a = nullptr;
        node tail = nullptr;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            insertLast(a,tail,x);
        }
        xoanode(a);
        in(a);
        delete(a);
    }
    
    return 0;
}