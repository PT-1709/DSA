// tìm node mid và in ra giá trị
// sử dụng fast - slow 

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node* next;
};

typedef struct Node* node;

node MakeNewNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = nullptr;
    return tmp;
}

void insertLast(node &a, int x){
    node tmp = MakeNewNode(x);
    if (a == nullptr){
        a = tmp;
    }
    else{
        node p = a;
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = tmp;
    }
}

int getMiddle(node a){
    node slowptr = a;
    node fastptr = a;
    while (fastptr != nullptr && fastptr->next != nullptr){
        fastptr = fastptr->next->next;
        slowptr = slowptr->next;
    }
    return slowptr->data;
}

void in(node a){
    while (a != nullptr){
        cout << a->data << " ";
        a = a->next;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    node a = nullptr;
    for (int i = 1; i <= 5; i++){
        insertLast(a,i);
    }

    in(a);
    cout << getMiddle(a) << endl;
    
    
    return 0;
}