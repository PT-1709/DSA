// https://leetcode.com/problems/palindrome-linked-list/submissions/1858694038/?source=submission-noac

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class LinkedList{
    private:
        struct Node{
            int data;
            Node* next;
            Node (int x) : data(x), next(nullptr){}
        };
        Node* head;
        Node* tail;
        stack <int> st;

    public:
        LinkedList(): head{nullptr}, tail{nullptr}{}
        void insertLast(int x){
            Node* tmp = new Node(x);
            if (head == nullptr){
                head = tmp;
                tail = tmp;
            }
            else{
                tail->next = tmp;
                tail = tmp;
            }
            
        }

        int dem(){
            Node* tmp = head;
            int cnt = 0;
            while (tmp != nullptr){
                cnt++;
                tmp = tmp->next;
            }
            return cnt;
        }

        void in(){
            Node* tmp = head;
            while (tmp != nullptr){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
        bool check(){
            if (head == nullptr || head->next == nullptr){
                return true;
            }

            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast->next != nullptr){
                st.push(slow->data);
                slow = slow->next;
                fast = fast->next->next;
            }
            if (fast != nullptr){
                slow = slow->next;
            }
            while (slow != nullptr){
                if (slow->data != st.top()){
                    return false;
                }
                st.pop();
                slow = slow->next;
            }
            return st.empty();
        }
        
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LinkedList link;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        link.insertLast(x);
    }
    if (link.check()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    
    return 0;
}
/* chx toi uu lam
bool check(){
    if (head == nullptr || head->next == nullptr){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    Node* trc = nullptr;
    while (fast && fast->next){
        trc= slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    int t = dem();
    if (t % 2 != 0){
        trc->next = slow->next;
        delete slow;
        t--;
    }
    int n = t / 2;
    Node* tmp = head;
    for (int i = 0; i < n ; i++){
        st.push(tmp->data);
        tmp = tmp->next;
    }

    while (tmp!= nullptr){
        if (tmp->data == st.top()){
            st.pop();
        }
        tmp = tmp->next;
    }
    return st.empty();
}
*/