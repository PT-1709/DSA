// https://www.hackerrank.com/challenges/reverse-a-linked-list/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

class LinkList{
    private: 
        struct Node{
            int data;
            Node* next;
            Node(int x) : data{x}, next{nullptr} {}
        };
        Node* head;
    public:
        LinkList(): head{nullptr}{}

        
        
        void insertFirst(int x){
            Node* tmp = new Node(x);
            if (head == nullptr){
                head = tmp;
            }
            else{
                tmp->next = head;
                head = tmp;
            }
        }

        void cleanLL(){
            while(head != nullptr){
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
            head = nullptr;
        }

        void in(){
            Node* p = head;
            while (p != nullptr){
                cout << p->data << " ";
                p = p->next;
            }
            cout << '\n';
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LinkList SLL;
    int tc; cin >> tc;
    while (tc--){
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            SLL.insertFirst(x);
        }
        SLL.in();
        SLL.cleanLL();

    }
    return 0;
}
