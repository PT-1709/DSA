// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int data;
    Node* next;
    Node* preve;
};

typedef struct Node* node;

class DoublyLinkedList{
    private:
        node head = nullptr;
        node tail = nullptr;
    public:
        node MakeNewNode(int x){
            node tmp = new Node();
            tmp->data = x;
            tmp->preve = nullptr;
            tmp->next = nullptr;
            return tmp;
        }

        void insertLast(int x){
            node tmp = MakeNewNode(x);
            if (head == nullptr){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tmp->preve = tail;
                tail = tmp;
            }
        }

        void in(){
            node tmp = head;
            while (head != nullptr){
                cout << head->data << " ";
                head = head->next;
            }
            cout << '\n';
        }

        void deleteLinkList(){
            while (head != nullptr){
                node tmp = head;
                head = head->next;
                delete tmp;
            }
            head = nullptr;
            tail = nullptr;
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    DoublyLinkedList DLL;
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            DLL.insertLast(x);
        }
        DLL.in();
        DLL.deleteLinkList();
    }
    
    return 0;
}