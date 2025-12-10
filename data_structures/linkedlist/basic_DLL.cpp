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

        int dem(){
            node p = head;
            int cnt = 0;
            while (p != nullptr){
                cnt++;
                p = p->next;
            }
            return cnt;
        }

        void insertMiddle(int x, int k){
            int t = dem();
            if (k < 0 || k > t+1){
                cout << "Kothethem\n";
                return;
            }
            else{
                if (k == 1){
                    insertFirst(x);
                }
                else if (k == t + 1){
                    insertLast(x);
                }
                else{
                    node tmp = MakeNewNode(x);
                    node trc = nullptr, sau = head;
                    for (int i = 0; i < k - 1; i++){
                        trc = sau;
                        sau = sau->next;
                    }
                    tmp->next = sau;
                    sau->preve = tmp;
                    trc->next = tmp;
                    tmp->preve = trc;
                    //delete tmp;
                }
            }
        }

        void deleteFirst(){
            if (head == nullptr){
                cout << "Kocozidexoa\n";
                return;
            }
            else{
                node tmp = head;
                head = head->next;
                head->preve = nullptr;
                delete tmp;
            }
        }

        void deleteLast(){
            if (head == nullptr){
                cout << "Kocozidexoa\n";
                return;
            }
            else{
                node tmp = tail;
                tail = tail->preve;
                tail->next = nullptr;
                delete tmp;
            }
        }

        void deleteMiddle(int k){
            int t = dem();
            if (k < 0 || k > t){
                cout << "KKohople\n";
                return;
            }
            else{
                node trc = nullptr, sau = head;
                for (int i = 0; i < k - 1; i++){
                    trc = sau;
                    sau = sau->next;
                }
                node tmp = sau;
                sau = sau->next;
                trc->next = sau;
                delete tmp;
            }
        }

        void in(){
            node p = head;
            while (p != nullptr){
                cout << setw(2) << setfill('0') << p->data << " ";
                p = p->next;
            }
            cout << '\n';
        }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    DoublyLinkedList DLL;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        DLL.insertLast(i);
    }
    int x; cin >> x;
    DLL.deleteMiddle(x);
    DLL.in();


    
    
    return 0;
}