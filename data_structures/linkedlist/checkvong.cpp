// kiểm tra linked list có cycle ko
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    
    return 0;
}