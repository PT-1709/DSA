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

void insertLast(node &head, node &tail, int x){
    node tmp = MakeNewNode(x);
    if (head == nullptr){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tmp;
    }
}

void deleteNode(node &head){
    while (head != nullptr){
        node tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}

void in(node head){
    while (head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}

node GopNode(node head1, node head2){
    node mergeNode = nullptr;
    node tailMer = nullptr;
    while (head1 != nullptr && head2 != nullptr){
        if (head1->data <= head2->data){
            node tmp = MakeNewNode(head1->data);
            if (mergeNode == nullptr){
                mergeNode = tmp;
                tailMer = tmp;
                head1 = head1->next;
            }
            else{
                tailMer->next = tmp;
                tailMer = tmp;
                head1 = head1->next;
            }
        }
        else{
            node tmp = MakeNewNode(head2->data);
            if (mergeNode == nullptr){
                mergeNode = tmp;
                tailMer = tmp;
                head2 = head2->next;
            }
            else{
                tailMer->next = tmp;
                tailMer = tmp;
                head2 = head2->next;
            }
        }
    }
    while (head1 != nullptr){
        node tmp = MakeNewNode(head1->data);
        if (mergeNode == nullptr){
            mergeNode = tmp;
            tailMer = tmp;
            head1 = head1->next;
        }
        else{
            tailMer->next = tmp;
            tailMer = tmp;
            head1 = head1->next;
        }
    }
    while (head2 != nullptr){
        node tmp = MakeNewNode(head2->data);
        if (mergeNode == nullptr){
            mergeNode = tmp;
            tailMer = tmp;
            head2 = head2->next;
        }
        else{
            tailMer->next = tmp;
            tailMer = tmp;
            head2 = head2->next;
        }
    }
    return mergeNode;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    while (tc--){
        node head1 = nullptr;
        node tail1 = nullptr;
        node head2 = nullptr;
        node tail2 = nullptr;

        int a; cin >> a;
        for (int i = 0; i < a; i++){
            int x; cin >> x;
            insertLast(head1,tail1,x);
        }
        int b; cin >> b;
        for (int i = 0; i < b; i++){
            int x; cin >> x;
            insertLast(head2,tail2,x);
        }
    

        node result = GopNode(head1, head2);
        in(result);

        deleteNode(head1);
        deleteNode(head2);
        deleteNode(result);

    }
    
    return 0;
}

// so sánh các node với nhau, tạo 1 hàm để gộp 2 linkedlist vào