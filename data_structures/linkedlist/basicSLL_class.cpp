// class
#include <bits/stdc++.h>
using namespace std;
#define ll long long


class Linkedlist{
    private:
        struct Node{
            int data;
            Node* next;
            Node(int x) : data{x}, next{nullptr} {}   
        };
        Node* head;

    public:
        Linkedlist() : head{nullptr}{}// khai báo node head = nullptr
        void print(){   // ko đc dùng trực tiếp vì khi di chuyển nó sẽ di chuyển luôn và mất tất cả dữ liệu
            Node* tmp = head;
            while(tmp != nullptr){
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }

        int dem(){
            int cnt  =0; 
            Node* tmp = head;
            while (tmp != nullptr){
                cnt++;
                tmp = tmp->next;
            }
            return cnt;
        }

        void insertLast(int x){
            Node* tmp = new Node(x);
            if (head  == nullptr){
                head = tmp;
                return;
            }
            Node* p = head;
            while (p->next != nullptr){
                p = p->next;
            }
            p->next = tmp;
        }

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

        void insertMiddle(int x, int k){
            int sz = dem();
            if (k < 1 || k > sz+1){
                cout << "Ko the them vao vi bi loi vi tri\n";
                return;
            }
            else if (k == 1){
                insertFirst(x);
                return;
            }
            else if (k == sz+1){
                insertLast(x);
                return;
            }
            else{
                Node* tmp = new Node(x);
                Node* p = head;
                for (int i = 1; i <= k - 2; i++){
                    p = p->next;
                }
                tmp->next = p->next;
                p->next = tmp;
            }
        }

        void deleteFirst(){
            if (head == nullptr){
                cout << "Ko the xoa\n";
                return;
            }
            else{
                Node* p = head;
                head = head->next;
                delete p;
            }
        }

        void deleteLast(){
            if (head == nullptr){
                cout << "Ko the xoa\n";
                return;
            }
            else{
                Node* trc = nullptr;
                Node* sau = head;
                while(sau->next != nullptr){
                    trc = sau;
                    sau = sau->next;
                }
                trc->next = nullptr;
                delete sau;
            }
        }

        void deleteMiddle(int k){
            int t = dem();
            if (k < 1 || k > t+1){
                cout << "Ko the xoa\n";
                return;
            }
            else if (k == 1){
                deleteFirst();
            }
            else if (k == t){
                deleteLast();
            }
            else{
                Node* trc = nullptr;
                Node* sau = head;
                for (int i = 1; i < k ; i++){
                    trc = sau;
                    sau = sau->next;
                }
                trc->next = sau->next;
                delete sau;

            }
        }

        void deleteVal(int x){
            while (head != nullptr && head->data == x){
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
            if (head == nullptr){
                return;
            }
            Node* trc = nullptr;
            Node* sau = head;
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
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Linkedlist link;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        link.insertLast(x);
    }

    int x; cin >> x;
    link.deleteVal(x);
    link.print(); cout << endl;
    

     
    return 0;
}

// đối với class như trên, đang viết hàm trong class nên head thay đổi theo từng hàm vì vậy muốn thay đổi có thể 
// dùng trực tiếp hoặc in - đếm thì thông qua tạm