// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=true

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

        void insertFirst(int x){
            node tmp = MakeNewNode(x);
            if (head == nullptr){
                head = tmp;
            }
            else{
                tmp->next = head;
                head->preve = tmp;
                head = tmp;
            }
        }

        void chenPhuHop(int x){
            if (head == nullptr){
                node tmp = MakeNewNode(x);
                head = tmp;
                tail = tmp;
            }
            else if (x <= head->data){
                insertFirst(x);
            }
            else if (x >= tail->data){
                insertLast(x);
            }
            else{
                node trc= nullptr, sau = head;
                while (sau != nullptr && sau->data < x){
                    trc = sau;
                    sau = sau->next;
                }
                node tmp = MakeNewNode(x);
                tmp->next = sau;
                sau->preve = tmp;
                tmp->preve= trc;
                trc->next = tmp;
            }
        }

        void in(){
            node p = head;
            if (p == nullptr){
                cout << "kocozidein\n";
                return;
            }
            while (p != nullptr){
                cout << p->data << " ";
                p = p->next;
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
        for (int i = 0; i < n ; i++){
            int x; cin >> x;
            DLL.insertLast(x);
        }
        int x; cin >> x;
        DLL.chenPhuHop(x);
        DLL.in();
        DLL.deleteLinkList();
    }
    
    return 0;
}