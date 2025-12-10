// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem?isFullScreen=true

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

        int count(){
            Node* p = head;
            int cnt = 0;
            while (p != nullptr){
                cnt++;
                p = p->next;
            }
            return cnt;
        }
        
        void insertLast(int x){
            Node* tmp = new Node(x);
            if (head == nullptr){
                head = tmp;
            }
            else{
                Node* p = head;
                while (p->next != nullptr){
                    p = p->next;
                }
                p->next = tmp;
            }
        }
        
        vector<int> nguoc(){
            Node* p = head;
            vector<int> st;
            while (p != nullptr){
                st.push_back(p->data);
                p = p->next;
            }
            return st;
            st.clear();
        }
        void deleteLast(){
            while (head != nullptr){
                head = head->next;
            }
        }


    
        
};

int main(){
    LinkList SLL;
    
    int n; cin >> n;
    while (n--){
        int x; cin >> x;
        for (int i = 0; i < x; i++){
            int k; cin >> k;
            SLL.insertLast(k);
        }
        vector <int> PK = SLL.nguoc();
        for (auto it = PK.rbegin(); it != PK.rend(); it++){
            cout << *it << '\n';
        }
        SLL.deleteLast();
    }
    
    return 0;
}
