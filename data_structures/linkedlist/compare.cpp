// https://www.hackerrank.com/challenges/compare-two-linked-lists/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class LinkedList{
    private: 
        struct Node{
            int data;
            Node* next;
            Node(int x) : data {x}, next{nullptr}{}
        };
        Node* head1 = nullptr;
        Node* head2 = nullptr;
    public:
        int dem(Node* head){
            Node* p = head;
            int cnt = 0;
            while (p != nullptr){
                cnt++;
                p = p->next;
            }
            return cnt;
        }

        


};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    
    return 0;
}