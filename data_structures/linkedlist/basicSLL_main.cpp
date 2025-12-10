// làm theo struct
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct Node* node;

struct Node{
    int data;
    Node* next;
};


node newNode( int x){
    node p = new Node();
    p->data = x;
    p->next = nullptr;
    return p; 
}

int dem(node a){
    int cnt = 0;
    while (a != nullptr){
        a = a->next;
        cnt++;
    }
    return cnt;
}

void insertFirst(node &a, int x){
    node tmp = newNode(x);
    if (a == nullptr){
        a = tmp;
    }
    else{
        tmp->next = a;
        a = tmp;
    }
}

void insertLast(node &a, int x){
    node tmp = newNode(x);
    if(a == nullptr){
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

void insertMiddle(node &a, int t, int k){ // t là số mới,  k là vị trí
    int n = sizeof(a);
    if (k <= 0 || k > k+1){
        cout << "ko hop le]n";
    }
    if (n == 1){
        insertFirst(a,t);
        return;
    }
    else if (n == k + 1){
        insertLast(a,t);
        return ;
    }
    node p = a;
    for (int i = 1; i < k - 1; i++){
        p = p->next;
    }
    node tmp = newNode(t);
    tmp->next = p->next;
    p->next = tmp;
    

}   

void deletefirst(node &a){
    if (a == nullptr){
        cout << "Ko co gi de xoa\n";
        return;
    }
    else{
        node tmp = a;
        a = a->next;
        delete tmp;
    }
}

void deleteLast(node &a){
    if (a == nullptr){
        cout << "Ko co gi de xoa\n";
        return;
    }
    else{
        node trc = nullptr, sau = a;
        while (sau->next != nullptr){
            trc = sau;
            sau = sau->next;
        }
        trc->next = nullptr;
        delete sau;
    }
}

void deleteMiddle(node &a, int k){
    if (a == nullptr){
        cout << "Ko co gi de xoa\n";
        return;
    }
    int t = dem(a);
    if (t == 1){
        deletefirst(a);
    }
    else if ( k >= t){
        cout << "Ko hop le \n";
        return;
    }
    else if (t == k + 1){
        deleteLast(a);
    }
    else{
        node truoc = nullptr, sau = a;
        for (int i = 1; i < k; i++){
            truoc = sau;
            sau = sau->next;
        }
        truoc->next = sau->next;
        delete sau;
    }
    
}


void in(node a){ // ở đây đc dùng trực tiếp a vì a ko làm thay đổi giá trị còn &a có làm thay đổi
    while (a != nullptr){
        cout << a->data << " ";
        a = a->next;
    }
}

void deleteVal(node &a, int x){
    node p = a;
    while (p != nullptr && p->data == x){
        node tmp = p;
        p = p ->next;
        delete tmp;
    }
    if (a == nullptr){
        return;
    }
    node trc = nullptr, sau = a;
    while (sau != nullptr){
        if (sau->data == x){
            trc->next = sau->next;
            delete sau;
            sau = trc->next;
        }
        else{
            trc = sau;
            sau = sau->next;
        }
    }

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    node a = nullptr;
    int n; cin >> n;
    for (int i = 0; i < n ; i++){
        int x; cin >> x;
        insertLast(a,x);
    }

    int x; cin >> x;
    deleteVal(a,x);
    in(a);
    
    return 0;
}