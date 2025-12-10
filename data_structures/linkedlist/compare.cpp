// https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node* next;
};

typedef struct Node* node;

node MakeNewNode (int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

void insertLast(node &a, node &b, int x){
    node tmp = MakeNewNode(x);
    if (a == nullptr){
        a = tmp;
        b= tmp;
    }
    else{
        b->next = tmp;
        b= tmp;
    }
}


void deleteNode(node &head){
    while(head != nullptr){
        node tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

bool compareNode(node head1, node head2){
    node p = head1;
    node q = head2;
    while (p != nullptr && q != nullptr){
        if (p->data != q->data){
            return false;
        }
        p = p->next;
        q = q->next;
    }
    return (p == nullptr && q == nullptr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--){
        int a; cin >> a;
        node head1 = nullptr;
        node tail1 = nullptr;
        node head2 = nullptr;
        node tail2 = nullptr;
        for (int i = 0; i < a; i++){
            int x; cin >> x;
            insertLast(head1,tail1,x);
        }
        int b; cin >> b;
        for (int i = 0; i < b; i++){
            int x; cin >> x;
            insertLast(head2,tail2,x);
        }
        if (compareNode(head1, head2)){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
        deleteNode(head1);
        deleteNode(head2);

    }
    return 0;
}